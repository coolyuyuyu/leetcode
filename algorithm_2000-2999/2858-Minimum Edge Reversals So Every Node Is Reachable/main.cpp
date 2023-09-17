class Solution {
public:
    vector<int> dfs1(int n, vector<vector<int>>& edges) {
        vector<vector<int>> fwdGraph(n), bwdGraph(n);
        for (const auto& edge : edges) {
            fwdGraph[edge[0]].push_back(edge[1]);
            bwdGraph[edge[1]].push_back(edge[0]);
        }

        map<pair<int, int>, int> cache;
        std::function<int(int, int)> f = [&](int cur, int pre) {
            if (cache.find({cur, pre}) != cache.end()) {
                return cache[{cur, pre}];
            }

            int& ret = cache[{cur, pre}] = 0;
            for (int nxt : fwdGraph[cur]) {
                if (nxt != pre) {
                    ret += f(nxt, cur);
                }
            }
            for (int nxt : bwdGraph[cur]) {
                if (nxt != pre) {
                    ret += f(nxt, cur) + 1;
                }
            }

            return ret;
        };

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = f(i, -1);
        }

        return ret;
    }

    // Re-root approach
    vector<int> dfs2(int n, vector<vector<int>>& edges) {
        vector<vector<int>> fwdGraph(n), bwdGraph(n);
        for (const auto& edge : edges) {
            fwdGraph[edge[0]].push_back(edge[1]);
            bwdGraph[edge[1]].push_back(edge[0]);
        }

        std::function<int(int, int)> f1 = [&](int cur, int pre) {
            int ret = 0;
            for (int nxt : fwdGraph[cur]) {
                if (nxt != pre) {
                    ret += f1(nxt, cur);
                }
            }
            for (int nxt : bwdGraph[cur]) {
                if (nxt != pre) {
                    ret += f1(nxt, cur) + 1;
                }
            }

            return ret;
        };
        int cnt = f1(0, -1);

        vector<int> ret(n);
        std::function<void(int, int, int)> f2 = [&](int cur, int pre, int cnt) {
            ret[cur] = cnt;

            for (int nxt : fwdGraph[cur]) {
                if (nxt != pre) {
                    f2(nxt, cur, cnt + 1);
                }
            }
            for (int nxt : bwdGraph[cur]) {
                if (nxt != pre) {
                    f2(nxt, cur, cnt - 1);
                }
            }
        };
        f2(0, -1, cnt);

        return ret;
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        //return dfs1(n, edges);
        return dfs2(n, edges);
    }
};
