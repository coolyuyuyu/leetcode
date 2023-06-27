class Solution {
public:
    int byDp(vector<int>& nums, int k) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        vector<int> presum(n + 1);
        std::partial_sum(nums.begin(), nums.end(), presum.begin());
        std::function<int(int, int)> sum = [&](int lo, int hi) {
            return presum[hi] - presum[lo - 1];
        };

        // dp[i][numParts]: the minimized largest sum of the numParts split of nums[1:i]
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = INT_MAX;
        }
        for (int i = 1; i <= n; ++i) {
            for (int numParts = 1; numParts <= std::min(i, k); ++numParts) {
                dp[i][numParts] = INT_MAX;
                for (int j = i; numParts <= j; --j) {
                    dp[i][numParts] = std::min(dp[i][numParts], std::max(dp[j - 1][numParts - 1], sum(j, i)));
                }
            }
        }

        return dp[n][k];
    }

    int byBinarySearch(vector<int>& nums, int k) {
        std::function<bool(int)> fitLargestSumOfSplit = [&](int target) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (target < nums[i]) {
                    return false;
                }

                int j = i, sum = 0;
                for (; j < nums.size() && (sum + nums[j]) <= target; ++j) {
                    sum += nums[j];
                }

                ++cnt;
                i = j - 1;
            }

            return cnt <= k;
        };

        int lo = 0, hi = 1e9;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (fitLargestSumOfSplit(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int splitArray(vector<int>& nums, int k) {
        //return byDp(nums, k);
        return byBinarySearch(nums, k);
    }
};