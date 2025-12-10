class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int ret = 0;
        std::function<int(int, int)> dfs = [&](int cur, int pre) {
            int rem = values[cur] % k;
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                rem += dfs(nxt, cur);
                rem %= k;
            }

            if (rem == 0) {
                ++ret;
            }

            return rem;
        };
        dfs(0, -1);

        return ret;
    }
};
