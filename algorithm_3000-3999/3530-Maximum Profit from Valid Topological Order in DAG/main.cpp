class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        int pres[n];
        std::fill(pres, pres + n, 0);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            pres[v] |= (1 << u);
        }

        // state: binary representation of the nodes being placed in a valid topological order.
        // dp[state]: the maximum profit of the state
        int dp[(1 << n)];
        for (int s = 0; s < (1 << n); ++s) {
            dp[s] = INT_MIN;
        }
        dp[0] = 0;

        for (int k = 1; k <= n; ++k) {
            // Gosper's hack: Iterate all the n-bit state where there are k 1-bits.
            int state = (1 << k) - 1;
            while (state < (1 << n)) {
                int s = state;
                for (int v = 0; v < n; ++v) {
                    if ((s >> v) & 1) {
                        int t = s & ~(1 << v);
                        if (dp[t] == INT_MAX) { continue; }
                        if ((pres[v] & t) == pres[v]) {
                            dp[s] = std::max(dp[s], dp[t] + k * score[v]);
                        }
                    }
                }

                int c = state & -state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        return dp[(1 << n) - 1];

    }
};
