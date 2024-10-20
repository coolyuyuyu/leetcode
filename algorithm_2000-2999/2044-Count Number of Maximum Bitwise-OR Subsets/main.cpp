class Solution {
public:
    int byBruteForce(vector<int>& nums) {
        int n = nums.size();
        int target = std::accumulate(nums.begin(), nums.end(), 0, std::bit_or<int>());

        int ret = 0;
        for (int s = 0; s < (1 << n); ++s) {
            int sum = 0;
            for (int t = s, i = 0; t; t >>= 1, ++i) {
                if (t & 1) {
                    sum |= nums[i];
                }
            }
            if (sum == target) {
                ++ret;
            }
        }

        return ret;
    }

    int byDP(vector<int>& nums) {
        int n = nums.size();
        int target = std::accumulate(nums.begin(), nums.end(), 0, std::bit_or<int>());
        int m = 1 << (sizeof(int) * CHAR_BIT - __builtin_clz(target));

        nums.insert(nums.begin(), 0);

        // dp[i][v]: number of different non-empty subsets from nums[1:i] with bitwise OR equal to v
        int dp[n + 1][m];
        for (int i = 0; i <= n; ++i) {
            for (int v = 0; v < m; ++v) {
                dp[i][v] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int v = 0; v < m; ++v) {
                dp[i + 1][v] += dp[i][v];
                dp[i + 1][v | nums[i + 1]] += dp[i][v];
            }
        }

        return dp[n][target];
    }

    int byDFS(vector<int>& nums) {
        int n = nums.size();
        int target = std::accumulate(nums.begin(), nums.end(), 0, std::bit_or<int>());

        int ret = 0;
        std::function<int(int, int)> f = [&](int i, int sum) {
            if (i >= n) {
                return sum == target ? 1 : 0;
            }
            return f(i + 1, sum) + f(i + 1, sum | nums[i]);
        };
        return f(0, 0);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        //return byBruteForce(nums);
        return byDP(nums);
        //return byDFS(nums);
    }
};
