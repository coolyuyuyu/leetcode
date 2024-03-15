class Solution {
public:
    // hash + prefix
    int f1(vector<int>& nums, int goal) {
        int ret = 0;
        unordered_map<int, int> presum2cnt = {{0, 1}};
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ret += presum2cnt[sum - goal];
            ++presum2cnt[sum];
        }

        return ret;
    }

    // two pointers
    int f2(vector<int>& nums, int goal) {
        int n = nums.size();

        // dp[i]: the number of consecutive 0 from nums[i + 1];
        int dp[n];
        for (int i = n, cnt = 0; 0 < i--;) {
            dp[i] = cnt;
            if (nums[i] == 0) {
                ++cnt;
            }
            else {
                cnt = 0;
            }
        }

        int ret = 0;
        for (int lft = 0, rht = 0, sum = 0; lft < n; ++lft) {
            for (; rht <= lft || (sum < goal && rht < n); ++rht) {
                sum += nums[rht];
            }

            if (sum == goal) {
                ret += dp[rht - 1] + 1;
            }

            sum -= nums[lft];
        }

        return ret;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //return f1(nums, goal);
        return f2(nums, goal);
    }
};
