class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<pair<int, int>> graph[n];
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            graph[u].emplace_back(v, i);
            graph[v].emplace_back(u, i);
        }

        vector<int> ret;
        std::function<bool(int, int, int)> dfs = [&](int cur, int pre, int i) {
            bool flip = false;
            for (const auto& [nxt, j] : graph[cur]) {
                if (nxt == pre) { continue; }
                if (dfs(nxt, cur, j)) {
                    flip = !flip;
                }
            }

            if (flip == (start[cur] == target[cur])) {
                ret.push_back(i);
                return true;
            }
            return false;
        };
        if (dfs(0, -1, -1)) {
            ret = {-1};
        }
        else {
            std::sort(ret.begin(), ret.end());
        }

        return ret;
    }
};
