class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        int indegree[n]; std::fill(indegree, indegree + n, 0);
        for (int i = 0; i < n; ++i) {
            ++indegree[favorite[i]];
        }

        queue<int> q;
        bool visited[n]; std::fill(visited, visited + n, false);
        int depth[n]; std::fill(depth, depth + n, 1);
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                visited[i] = true;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            int nxt = favorite[cur];
            if (--indegree[nxt] == 0) {
                visited[nxt] = true;
                q.push(nxt);
            }
            depth[nxt] = depth[cur] + 1;
        }

        int maxCycleLen = 0;
        int sumLinkLen = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) { continue; }

            int len = 0;
            for (int j = i; visited[j] == false; ++len, j = favorite[j]) {
                visited[j] = true;
            }
            if (len >= 3) {
                maxCycleLen = std::max(maxCycleLen, len);
            }
            else if (len == 2) {
                sumLinkLen += depth[i] + depth[favorite[i]];
            }
        }

        return std::max(maxCycleLen, sumLinkLen);
    }
};
