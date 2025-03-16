class Solution {
public:
    // Time: O(n), Space: O(n)
    bool dp1(vector<int>& nums, int k, int capability) {
        int n = nums.size();

        // dp[i][0]: how many houses can be rubbed from house[0:i] and house[i] is NOT rubbed.
        // dp[i][0]: how many houses can be rubbed from house[0:i] and house[i] is rubbed.
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = (nums[0] <= capability ? 1 : INT_MIN);
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= capability) {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else {
                dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = INT_MIN;
            }
        }

        return std::max(dp[n - 1][0], dp[n - 1][1]) >= k;
    }

    // Time: O(n), Space: O(1)
    bool dp2(vector<int>& nums, int k, int capability) {
        int n = nums.size();

        // dpN[i]: how many houses can be rubbed from house[0:i] and house[i] is NOT rubbed.
        // dpY[i]: how many houses can be rubbed from house[0:i] and house[i] is rubbed.
        int dpN = 0;
        int dpY = (nums[0] <= capability ? 1 : INT_MIN);
        for (int i = 1; i < n; ++i) {
            int tmpN = dpN, tmpY = dpY;
            if (nums[i] <= capability) {
                dpN = std::max(tmpN, tmpY);
                dpY = tmpN + 1;
            }
            else {
                dpN = std::max(tmpN, tmpY);
                dpY = INT_MIN;
            }
        }

        return std::max(dpN, dpY) >= k;
    }

    // Time: O(n), Space: O(1)
    bool greedy(vector<int>& nums, int k, int capability) {
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] <= capability) {
                if (--k <= 0) {
                    return true;
                }
                ++i;
            }
        }

        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        auto [minItr, maxItr] = std::minmax_element(nums.begin(), nums.end());
        int lo = *minItr, hi = *maxItr;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            //if (dp1(nums, k, mid)) {
            //if (dp2(nums, k, mid)) {
            if (greedy(nums, k, mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
