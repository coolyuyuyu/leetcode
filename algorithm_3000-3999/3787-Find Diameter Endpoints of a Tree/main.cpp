class Solution {
public:
    string findSpecialNodes(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        string ret(n, '0');

        int dists[n];
        int maxDist;
        std::function<void(int, int, int)> dfs = [&](int cur, int pre, int dist) {
            dists[cur] = dist;

            maxDist = std::max(maxDist, dists[cur]);

            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                dfs(nxt, cur, dist + 1);
            }
        };

        std::fill(dists, dists + n, -1);
        maxDist = 0;
        dfs(0, -1, 0);
        int farest;
        for (int i = 0; i < n; ++i) {
            if (dists[i] == maxDist) {
                ret[i] = '1';
                farest = i;
            }
        }

        std::fill(dists, dists + n, -1);
        maxDist = 0;
        dfs(farest, -1, 0);
        for (int i = 0; i < n; ++i) {
            if (dists[i] == maxDist) {
                ret[i] = '1';
            }
        }

        return ret;
    }
};
