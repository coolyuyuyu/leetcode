class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int> graph[n];
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> cnts(n, 0);
        std::function<bool(int, int, int)> dfsFindPath = [&](int pre, int cur, int dst) {
            if (cur == dst) {
                return true;
            }

            for (int nxt : graph[cur]) {
                if (nxt == pre) {
                    continue;
                }
                if (dfsFindPath(cur, nxt, dst)) {
                    ++cnts[nxt];
                    return true;
                }
            }

            return false;
        };
        for (const auto& trip : trips) {
            ++cnts[trip[0]];
            dfsFindPath(-1, trip[0], trip[1]);
        }

        // dp[i][0]: the min total price of sub-tree rooted at i, and do not halve price[i]
        // dp[i][1]: the min total price of sub-tree rooted at i, and do halve price[i]
        vector<vector<int>> dp(n, vector<int>(2, -1));
        std::function<int(int, int, int)> dfsMinTotalPrice = [&](int pre, int cur, int half) {
            int& minTotalPrice = dp[cur][half];
            if (0 <= minTotalPrice) {
                return minTotalPrice;
            }

            minTotalPrice = price[cur] * cnts[cur];
            if (half) {
                minTotalPrice /= 2;
            }

            for (int nxt : graph[cur]) {
                if (nxt == pre) {
                    continue;
                }

                if (half) {
                    minTotalPrice += dfsMinTotalPrice(cur, nxt, 0);
                }
                else {
                    minTotalPrice += std::min(dfsMinTotalPrice(cur, nxt, 0), dfsMinTotalPrice(cur, nxt, 1));
                }
            }

            return minTotalPrice;
        };

        int src = 0;
        return std::min(dfsMinTotalPrice(-1, src, 0), dfsMinTotalPrice(-1, src, 1));
    }
};
