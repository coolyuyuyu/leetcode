class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int ret = 0;
        for (int lft = 0, rht = 0, product = 1; lft < n; ++lft) {
            if (rht < lft) {
                rht = lft;
                product = 1;
            }
            for (; rht < n && product * nums[rht] < k; ++rht) {
                product *= nums[rht];
            }

            ret += (rht - lft);

            product /= nums[lft];
        }

        return ret;
    }
};
