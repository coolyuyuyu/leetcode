class Solution {
public:
    int byBruteForce(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0, std::bit_or<int>());

        int ret = 0;
        for (int s = 1; s < (1 << n); ++s) {
            int t = 0;
            for (int ss = s, i = 0; ss; ss >>= 1, ++i) {
                if (ss & 1) {
                    t |= nums[i];
                }
            }
            if (t == sum) {
                ++ret;
            }
        }

        return ret;
    }

    int byDP(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0, std::bit_or<int>());
        int m = 1 << (sizeof(int) * CHAR_BIT - __builtin_clz(sum));

        // dp[num]: the number of different non-empty subsets whose bitwise or is num
        int dp[m], tmp[m];
        for (int num = 0; num < m; ++num) {
            dp[num] = 0;
        }
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            std::copy(dp, dp + m, tmp);
            std::fill(dp, dp + m, 0);
            for (int num = 0; num < m; ++num) {
                dp[num] += tmp[num];
                dp[num | nums[i]] += tmp[num];
            }
        }

        return dp[sum];
    }

    int countMaxOrSubsets(vector<int>& nums) {
        //return byBruteForce(nums);
        return byDP(nums);
    }
};
