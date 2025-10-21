class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ret = 0;
        for (int i = 0, sign = 1; i < nums.size(); ++i, sign *= -1) {
            ret += sign * nums[i];
        }

        return ret;
    }
};
