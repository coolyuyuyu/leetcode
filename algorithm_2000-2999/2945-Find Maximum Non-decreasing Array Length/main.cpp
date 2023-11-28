class Solution {
public:
    // Time: O(n^2), TLE
    int dp1(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        // dp[i]: the sum of last subarray ending at i from nums[1:i]
        // len[i]: the maximum length of a non-decreasing array that can be made from nums[1:i]
        int dp[n + 1];
        dp[0] = 0;
        int len[n + 1];
        len[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int subsum = nums[i];
            int j = i - 1;
            while (j >= 1 && dp[j] > subsum) {
                subsum += nums[j];
                j--;
            }
            dp[i] = subsum;
            len[i] = len[j] + 1;
        }

        return len[n];
    }

    // Time: O(nlogn)
    int dp2(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        // dp[i]: the sum of last subarray ending at i from nums[1:i]
        // len[i]: the maximum length of a non-decreasing array that can be made from nums[1:i]
        int dp[n + 1];
        dp[0] = 0;
        int len[n + 1];
        len[0] = 0;

        // X X [X X X] [X X]
        //          j     i
        // dp[j] <= dp[i]
        // dp[j] <= presum[i] - presum[j]
        // dp[j] + presum[j] <= presum[i]

        long presum[n + 1];
        presum[0] = nums[0];
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i];
        }

        map<long, int> m;
        m[0] = 0;

        for (int i = 1; i <= n; ++i) {
            auto itr = std::prev(m.upper_bound(presum[i]));
            int j = itr->second;

            dp[i] = presum[i] - presum[j];
            len[i] = len[j] + 1;

            while (!m.empty() && m.rbegin()->first >= presum[i] + dp[i]) {
                m.erase(std::prev(m.end()));
            }

            m[dp[i] + presum[i]] = i;
        }

        return len[n];
    }

    int findMaximumLength(vector<int>& nums) {
        //return dp1(nums);
        return dp2(nums);
    }
};
