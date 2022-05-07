class Solution {
public:
    // Time: O(MlogM + N), Space: O(N)
    long long dp1(int n, vector<vector<int>>& rides) {
        std::sort(rides.begin(), rides.end());

        vector<long long> dp(n + 1, 0); // dp[i]: maximum earning from point 1 to point i.
        for (size_t j = 0, i = 1; i < dp.size(); ++i) {
            dp[i] = std::max(dp[i], dp[i - 1]);
            for (; j < rides.size() && i == rides[j][0]; ++j) {
                dp[rides[j][1]] = std::max(dp[rides[j][1]], dp[i] + rides[j][1] - rides[j][0] + rides[j][2]);
            }

        }

        return dp.back();
    }

    // Time: O(N), Space: O(2N)
    long long dp2(int n, vector<vector<int>>& rides) {
        unordered_multimap<int, pair<int, int>> dict; // start -> <end, profit>, profit = end - start + tip
        for (const auto& ride : rides) {
            dict.emplace(ride[0], pair<int, int>{ride[1], ride[1] - ride[0] + ride[2]});
        };

        vector<long long> dp(n + 1, 0); // dp[i]: maximum earning from point 1 to point i.
        for (size_t j = 0, i = 1; i < dp.size(); ++i) {
            dp[i] = std::max(dp[i], dp[i - 1]);

            const auto p = dict.equal_range(i);
            for (auto itr = p.first; itr != p.second; ++itr) {
                const auto& [end, profit] = itr->second;
                dp[end] = std::max(dp[end], dp[i] + profit);
            }
        }

        return dp.back();
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        //return dp1(n, rides);
        return dp2(n, rides);
    }
};
