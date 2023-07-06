class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int ret = INT_MAX;
        for (int lft = 0, rht = 0, sum = 0; lft < n; ++lft) {
            while (rht < n && sum < target) {
                sum += nums[rht++];
            }

            if (target <= sum) {
                ret = std::min(ret, rht - lft);
            }

            sum -= nums[lft];
        }

        return ret == INT_MAX ? 0 : ret;
    }
};
