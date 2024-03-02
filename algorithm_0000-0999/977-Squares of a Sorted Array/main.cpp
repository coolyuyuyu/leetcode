class Solution {
public:
    // Time: O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> ret(n);
        for (int lft = 0, rht = n - 1, i = n - 1; lft <= rht; --i) {
            if (abs(nums[lft]) <= abs(nums[rht])) {
                ret[i] = nums[rht] * nums[rht];
                --rht;
            }
            else {
                ret[i] = nums[lft] * nums[lft];
                ++lft;
            }
        }

        return ret;
    }
};
