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
        std::function<int(int, int)> f = [&](int cur, int pre) {
            int remaining = values[cur];
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                remaining += f(nxt, cur);
            }
            remaining %= k;

            if (remaining == 0) {
                ++ret;
            }

            return remaining;
        };
        f(0, -1);

        return ret;
    }
};
