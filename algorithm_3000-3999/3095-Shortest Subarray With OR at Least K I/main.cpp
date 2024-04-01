class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int ret = INT_MAX;
        for (int lft = 0; lft < n; ++lft) {
            int sum = 0;
            for (int rht = lft; rht < n; ++rht) {
                for (int i = 0, num = nums[rht]; num; ++i, num >>= 1) {
                    if (num & 1) {
                        sum |= (1 << i);
                    }
                }
                if (sum >= k) {
                    ret = std::min(ret, rht - lft + 1);
                    break;
                }
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }
};
