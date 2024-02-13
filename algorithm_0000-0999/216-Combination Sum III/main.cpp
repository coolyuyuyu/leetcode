class Solution {
public:
    vector<vector<int>> byDP(int k, int n) {
        // dp[i][j]: list of all possible valid combinations of j numbers that sum up to i
        vector<vector<int>> dp[n + 1][k + 1];
        dp[0][0] = {{}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                for (const auto& comb : dp[i][j]) {
                    for (int d = (comb.empty() ? 0 : comb.back()) + 1; d <= 9 && d + i <= n; ++d) {
                        dp[i + d][j + 1].push_back(comb);
                        dp[i + d][j + 1].back().push_back(d);
                    }
                }
            }
        }

        return dp[n][k];
    }

    vector<vector<int>> byDFS(int k, int n) {
        vector<vector<int>> ret;
        std::function<void(vector<int>&, int, int)> f = [&](vector<int>& comb, int sum, int cur) {
            if (sum > n) { return; }
            if (comb.size() > k) { return; }
            if (comb.size() == k && sum == n) {
                ret.push_back(comb);
                return;
            }

            for (int d = cur; d <= 9; ++d) {
                comb.push_back(d);
                f(comb, sum + d, d + 1);
                comb.pop_back();
            }
        };

        vector<int> comb;
        f(comb, 0, 1);

        return ret;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        //return byDP(k, n);
        return byDFS(k, n);
    }
};
