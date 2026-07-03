class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int depth = 0;
        int depths[n];
        for (queue<pair<int, int>> q({{0, 0}}); !q.empty(); ++depth) {
            for (int i = q.size(); 0 < i--;) {
                auto [cur, pre] = q.front();
                q.pop();

                depths[cur] = depth;

                for (int nxt : graph[cur]) {
                    if (nxt == pre) { continue; }
                    q.emplace(nxt, cur);
                }
            }
        }

        int logD = std::ceil(std::log2(depth));

        int ancestors[logD + 1][n];
        for (queue<pair<int, int>> q({{0, 0}}); !q.empty(); ++depth) {
            for (int i = q.size(); 0 < i--;) {
                auto [cur, pre] = q.front();
                q.pop();

                ancestors[0][cur] = pre;

                for (int nxt : graph[cur]) {
                    if (nxt == pre) { continue; }
                    q.emplace(nxt, cur);
                }
            }
        }
        for (int k = 1; k <= logD; ++k) {
            for (int v = 0; v < n; ++v) {
                ancestors[k][v] = ancestors[k - 1][ancestors[k - 1][v]];
            }
        }

        std::function<int(int, int)> computeLCA = [&](int u, int v) {
            if (depths[u] > depths[v]) {
                std::swap(u, v);
            }

            int diff = depths[v] - depths[u];
            for (int k = 0; diff; ++k, diff >>= 1) {
                if (diff & 1) {
                    v = ancestors[k][v];
                }

            }

            if (u == v) {
                return u;
            }

            for (int k = std::ceil(std::log2(depths[u])); k >= 0; --k) {
                if (ancestors[k][u] != ancestors[k][v]) {
                    u = ancestors[k][u];
                    v = ancestors[k][v];
                }
            }

            return ancestors[0][u];;
        };

        std::function<int(int, int)> qpow = [](int base, int exp) {
            int M = 1e9 + 7;

            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret = (1L * ret * base) % M;
                }
                base = (1L * base * base) % M;
            }

            return ret;
        };

        int m = queries.size();
        vector<int> ret(m);
        for (int i = 0; i < m; ++i) {
            int u = queries[i][0] - 1, v = queries[i][1] - 1;
            if (u == v) {
                ret[i] = 0;
                continue;
            }
            int lca = computeLCA(u, v);
            int dist = depths[u] + depths[v] - 2 * depths[lca];
            ret[i] = qpow(2, dist - 1);
        }

        return ret;
    }
};
