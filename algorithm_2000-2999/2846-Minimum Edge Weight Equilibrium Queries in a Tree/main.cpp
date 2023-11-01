class Solution {
public:
    vector<int> linearLCA(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int root = 0;

        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // cnt[i][j]: the number of edges weighted j in the path from root to node i
        int cnt[n][27];
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= 26; ++j) {
                cnt[i][j] = 0;
            }
        }
        // depth[i]: the depth of node i
        int depth[n];
        // parent[i]: the parent of node i
        int parent[n];
        parent[root] = -1;

        // tmp[i]: the number of edges weighted i
        int tmp[27];
        std::fill(std::begin(tmp), std::end(tmp), 0);
        std::function<void(int, int, int)> dfs = [&](int cur, int pre, int d) {
            parent[cur] = pre;
            depth[cur] = d;

            for (const auto& [nxt, w] : graph[cur]) {
                if (nxt == pre) { continue; }

                ++tmp[w];
                std::copy(std::begin(tmp), std::end(tmp), cnt[nxt]);
                dfs(nxt, cur, d + 1);
                --tmp[w];
            }
        };
        dfs(root, -1, 0);

        std::function<int(int, int)> findLCA = [&](int a, int b) {
            while (a != b) {
                if (depth[a] < depth[b]) {
                    b = parent[b];
                }
                else if (depth[a] == depth[b]) {
                    a = parent[a];
                    b = parent[b];
                }
                else {
                    a = parent[a];
                }
            }

            return a;
        };

        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int a = queries[i][0], b = queries[i][1], lca = findLCA(a, b);
            int sum = 0, maxCnt = 0;
            for (int j = 1; j <= 26; ++j) {
                int cntOfJ = cnt[a][j] + cnt[b][j] - 2 * cnt[lca][j];
                sum += cntOfJ;
                maxCnt = std::max(maxCnt, cntOfJ);
            }

            ret[i] = sum - maxCnt;
        }

        return ret;
    }

    vector<int> binaryLCA(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int root = 0;

        vector<pair<int, int>> graph[n];
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // cnt[i][j]: the number of edges weighted j in the path from root to node i
        int cnt[n][27];
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= 26; ++j) {
                cnt[i][j] = 0;
            }
        }
        // depth[i]: the depth of node i
        int depth[n];
        // parent[i]: the parent of node i
        int parent[n];
        parent[root] = -1;

        // tmp[i]: the number of edges weighted i
        int tmp[27];
        std::fill(std::begin(tmp), std::end(tmp), 0);
        std::function<void(int, int, int)> dfs = [&](int cur, int pre, int d) {
            parent[cur] = pre;
            depth[cur] = d;

            for (const auto& [nxt, w] : graph[cur]) {
                if (nxt == pre) { continue; }

                ++tmp[w];
                std::copy(std::begin(tmp), std::end(tmp), cnt[nxt]);
                dfs(nxt, cur, d + 1);
                --tmp[w];
            }
        };
        dfs(root, -1, 0);

        int m = ceil(log2(n));
        // ancestor[i][j] = the 2^j ancestor of node i
        int ancestor[n][m + 1];
        for (int i = 0; i < n; ++i) {
            ancestor[i][0] = parent[i];
        }
        ancestor[root][0] = 0;
        for (int j = 1; j <= m; ++j) {
            for (int i = 0; i < n; ++i) {
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
            }
        }
        std::function<int(int, int)> getKthAncestor = [&](int v, int k) {
            for (int j = 0; k; ++j, k >>= 1) {
                if (k & 1) {
                    v = ancestor[v][j];
                }
            }

            return v;
        };
        std::function<int(int, int)> findLCA = [&](int a, int b) {
            if (depth[a] < depth[b]) {
                b = getKthAncestor(b, depth[b] - depth[a]);
            }
            else if (depth[a] > depth[b]) {
                a = getKthAncestor(a, depth[a] - depth[b]);
            }

            int lo = 0, hi = depth[a];
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (getKthAncestor(a, mid) == getKthAncestor(b, mid)) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }

            return getKthAncestor(a, lo);
        };

        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int a = queries[i][0], b = queries[i][1], lca = findLCA(a, b);
            int sum = 0, maxCnt = 0;
            for (int j = 1; j <= 26; ++j) {
                int cntOfJ = cnt[a][j] + cnt[b][j] - 2 * cnt[lca][j];
                sum += cntOfJ;
                maxCnt = std::max(maxCnt, cntOfJ);
            }

            ret[i] = sum - maxCnt;
        }

        return ret;
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        //return linearLCA(n, edges, queries);
        return binaryLCA(n, edges, queries);
    }
};
