class Solution {
public:
    int byThreePass(vector<int>& nums) {
        int n = nums.size();

        int cntLft1[n];
        for (int i = 0; i < n; ++i) {
            cntLft1[i] = ((i > 0 ? cntLft1[i - 1] : 0) + 1) * nums[i];
        }
        int cntRht1[n];
        for (int i = n - 1; i >= 0; --i) {
            cntRht1[i] = (((i + 1 < n) ? cntRht1[i + 1] : 0) + 1) * nums[i];
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int len = (i > 0 ? cntLft1[i - 1] : 0) + ((i + 1 < n) ? cntRht1[i + 1] : 0);
            ret = std::max(ret, len);
        }

        return ret;
    }

    int byDP(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), -1);

        // dp[i][0]: the length of longest subarray ending at nums[i] and the number of element zero is 0
        // dp[i][1]: the length of longest subarray ending at nums[i] and the number of element zero is 1
        int dp[n + 1][2];
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            if (nums[i] == 0) {
                dp[i][0] = 0;
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] + 1;
            }
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            ret = std::max({ret, dp[i][0] - 1, dp[i][1] - 1});
        }

        return ret;
    }

    int bySlidingWindow(vector<int>& nums) {
        int ret = 0;
        for (int l = 0, r = 0, n = nums.size(), cnt0 = 0; l < n; ++l) {
            for (; r < n && (nums[r] == 1 || cnt0 == 0); ++r) {
                cnt0 += (nums[r] == 0);
            }

            ret = std::max(ret, r - l - 1);

            cnt0 -= (nums[l] == 0);
        }

        return ret;
    }

    int longestSubarray(vector<int>& nums) {
        //return byThreePass(nums);
        //return byDP(nums);
        return bySlidingWindow(nums);
    }
};
