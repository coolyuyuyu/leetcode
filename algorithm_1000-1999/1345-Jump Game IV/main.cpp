class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[arr[i]].push_back(i);
        }

        int src = 0, dst = n - 1;
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(src);
        visited[src] = true;
        for (int steps = 0; !q.empty(); ++steps) {
            for (int len = q.size(); 0 < len--;) {
                int i = q.front();
                q.pop();

                if (i == dst) {
                    return steps;
                }

                if (0 < i && !visited[i - 1]) {
                    q.push(i - 1);
                    visited[i - 1] = true;
                }
                if ((i + 1) < n && !visited[i + 1]) {
                    q.push(i + 1);
                    visited[i + 1] = true;
                }
                if (m.find(arr[i]) != m.end()) {
                    for (int j : m[arr[i]]) {
                        if (visited[j]) {
                            continue;
                        }

                        q.push(j);
                        visited[j] = true;
                    }
                    m.erase(arr[i]);
                }
            }
        }

        return -1;
    }
};
