class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        std::function<vector<int>(int)> bfs = [&](int src) {
            vector<int> ret(n);

            queue<pair<int, int>> q;
            q.emplace(src, -1);
            for (int d = 0; !q.empty(); ++d) {
                for (int i = q.size(); 0 < i--;) {
                    auto [cur, pre] = q.front();
                    q.pop();

                    ret[cur] = d;

                    for (int nxt : graph[cur]) {
                        if (nxt == pre) { continue; }
                        q.emplace(nxt, cur);
                    }
                }
            }

            return ret;
        };

        vector<int> dx = bfs(x);
        vector<int> dy = bfs(y);
        vector<int> dz = bfs(z);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int dists[3] = {dx[i], dy[i], dz[i]};
            std::sort(dists, dists + 3);
            long long a = dists[0], b = dists[1], c = dists[2];
            if ((a * a + b * b)== c * c) {
                ++ret;
            }
        }

        return ret;
    }
};
