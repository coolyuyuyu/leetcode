class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<int>> fwdGraph(n), bwdGraph(n);
        for (const auto& edge : edges) {
            fwdGraph[edge[0]].push_back(edge[1]);
            bwdGraph[edge[1]].push_back(edge[0]);
        }

        map<pair<int, int>, int> cache;
        std::function<int(int, int)> dfs = [&](int cur, int pre) {
            if (cache.find({cur, pre}) != cache.end()) {
                return cache[{cur, pre}];
            }

            int& ret = cache[{cur, pre}] = 0;
            for (int nxt : fwdGraph[cur]) {
                if (nxt != pre) {
                    ret += dfs(nxt, cur);
                }
            }

            for (int nxt : bwdGraph[cur]) {
                if (nxt != pre) {
                    ret += dfs(nxt, cur) + 1;
                }
            }

            return ret;
        };

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = dfs(i, -1);
        }

        return ret;
    }
};
