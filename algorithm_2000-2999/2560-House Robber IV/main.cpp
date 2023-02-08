class Solution {
public:
    // check if the rubber can rub at least k houses with capability <= maxCapability
    // dp approach
    // Time: O(n), Space: O(n))
    bool dp1(const vector<int>& nums, int maxCapability, int k) {
        size_t n = nums.size();

        vector<array<int, 2>> dp(n);
        // dp[i][0]: the max number of rubbed house from house[0:i-1] and do not rub house[i]
        // dp[i][1]: the max number of rubbed house from house[0:i-1] and do rub house[i]
        dp[0][0] = 0;
        dp[0][1] = (nums[0] <= maxCapability ? 1 : INT_MIN);
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] <= maxCapability) {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = INT_MIN;
            }
        }

        return k <= std::max(dp[n - 1][0], dp[n - 1][1]);
    }

    // check if the rubber can rub at least k houses with capability <= maxCapability
    // dp approach
    // Time: O(n), Space: O(1))
    bool dp2(const vector<int>& nums, int maxCapability, int k) {
        int rubN = 0;
        int rubY = (nums[0] <= maxCapability ? 1 : INT_MIN);
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] <= maxCapability) {
                int tmpN = std::max(rubN, rubY);
                int tmpY = rubN + 1;
                rubN = tmpN, rubY = tmpY;
            }
            else {
                rubN = std::max(rubN, rubY);
                rubY = INT_MIN;
            }
        }

        return k <= std::max(rubN, rubY);
    }

    // check if the rubber can rub at least k houses with capability <= maxCapability
    // greedy approach
    // Time: O(n), Space: O(1))
    bool greedy(const vector<int>& nums, int maxCapability, int k) {
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] <= maxCapability) {
                if (--k == 0) {
                    return true;
                }
                ++i;
            }
        }

        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        const auto [minItr, maxItr] = std::minmax_element(nums.begin(), nums.end());
        int lo = *minItr, hi = *maxItr;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            //if (dp1(nums, mid, k)) {
            //if (dp2(nums, mid, k)) {
            if (greedy(nums, mid, k)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
