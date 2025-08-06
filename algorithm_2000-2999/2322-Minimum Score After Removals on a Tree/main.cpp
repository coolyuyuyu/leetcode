class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), m = edges.size();

        vector<int> graph[n];
        vector<int> degrees(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            ++degrees[u];
            ++degrees[v];
        }

        int total = 0; // the xor sum of all nodes;
        unordered_set<int> descendants[n]; // descendants[v]: the descendants of node v
        vector<int> vals = nums; // vals[v]: the xor sum rooted at node v
        vector<bool> visited(n, false);
        queue<int> q;
        for (int v = 0; v < n; ++v) {
            total ^= nums[v];
            if (degrees[v] == 1) {
                q.push(v);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            for (int nxt : graph[cur]) {
                if (!visited[nxt]) {
                    descendants[nxt].insert(descendants[cur].begin(), descendants[cur].end());
                    descendants[nxt].insert(cur);
                    vals[nxt] ^= vals[cur];
                }
                if (--degrees[nxt] == 1) {
                    q.push(nxt);
                }
            }
        }

        int ret = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                // assume a is the lower node of break edge a-b
                int a = edges[i][0], b = edges[i][1];
                if (descendants[a].find(b) != descendants[a].end()) {
                    std::swap(a, b);
                }
                // assume c is the lower node of break edge c-d
                int c = edges[j][0], d = edges[j][1];
                if (descendants[c].find(d) != descendants[c].end()) {
                    std::swap(c, d);
                }

                pair<int, int> mnmx;
                if (descendants[a].find(c) != descendants[a].end()) {
                    mnmx = std::minmax({vals[c], vals[a] ^ vals[c], total ^ vals[a]});
                }
                else if (descendants[c].find(a) != descendants[c].end()) {
                    mnmx = std::minmax({vals[a], vals[c] ^ vals[a], total ^ vals[c]});
                }
                else {
                    mnmx = std::minmax({vals[a], vals[c], total ^ vals[a] ^ vals[c]});
                }

                auto [mn, mx] = mnmx;
                ret = std::min(ret, mx - mn);
            }
        }

        return ret;
    }
};
