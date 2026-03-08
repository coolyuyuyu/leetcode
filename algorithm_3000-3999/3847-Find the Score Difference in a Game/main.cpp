class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ret = 0;
        for (int i = 0, n = nums.size(), sign = +1; i < n; ++i) {
            if (nums[i] & 1) {
                sign *= -1;
            }
            if (i % 6 == 5) {
                sign *= -1;
            }
            ret += sign * nums[i];
        }

        return ret;
    }
};
