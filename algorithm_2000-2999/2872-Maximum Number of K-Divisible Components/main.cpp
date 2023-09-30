class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int ret = 0;
        std::function<int(int, int)> f = [&](int cur, int pre) {
            int remaining = values[cur];
            for (int nxt : graph[cur]) {
                if (nxt == pre) { continue; }
                remaining += f(nxt, cur);
            }

            if (remaining % k == 0) {
                ++ret;
                return 0;
            }
            else {
                return remaining;
            }
        };
        f(0, -1);

        return ret;
    }
};
