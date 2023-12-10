class Solution {
public:
    bool bfs(vector<int>& arr, int start) {
        int n = arr.size();

        bool visited[n];
        std::fill(visited, visited + n, false);

        queue<int> q({start});
        visited[start] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (arr[v] == 0) {
                return true;
            }

            int rht = v + arr[v];
            if (rht < n && visited[rht] == false) {
                q.push(rht);
                visited[rht] = true;
            }
            int lft = v - arr[v];
            if (lft >= 0 && visited[lft] == false) {
                q.push(lft);
                visited[lft] = true;
            }
        }

        return false;
    }

    bool dfs(vector<int>& arr, int start) {
        int n = arr.size();

        bool visited[n];
        std::fill(visited, visited + n, false);

        std::function<bool(int)> f = [&](int i) {
            if (i < 0 || i >= n) { return false; }
            if (visited[i]) { return false; }

            if (arr[i] == 0) { return true; }

            visited[i] = true;
            if (f(i + arr[i])) {
                return true;
            }
            if (f(i - arr[i])) {
                return true;
            }

            return false;
        };

        return f(start);
    }

    bool canReach(vector<int>& arr, int start) {
        //return bfs(arr, start);
        return dfs(arr, start);
    }
};
