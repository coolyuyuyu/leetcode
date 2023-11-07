class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();

        // nums[i_j] - nums[i_j-1] >= i_j - i_j-1
        // => nums[i_j] - i_j >= nums[i_j-1] - i_j-1

        int arr[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i] - i;
        }
        // find maximum sum (on nums) of increaing subsequence from arr

        // dp[x]: the maximum sum (on num) of increaing subsequnce ending at x
        map<int, long long> dp;

        long long ret = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            int x = arr[i];
            auto itr = dp.upper_bound(x);
            if (itr != dp.begin()) {
                itr = std::prev(itr);
                dp[x] = std::max(0LL, itr->second) + nums[i];
            }
            else {
                dp[x] = nums[i];
            }

            ret = std::max(ret, dp[x]);

            for (auto itr = std::next(dp.find(x)); itr != dp.end() && dp[x] >= itr->second;) {
                itr = dp.erase(itr);
            }
        }

        return ret;
    }
};
