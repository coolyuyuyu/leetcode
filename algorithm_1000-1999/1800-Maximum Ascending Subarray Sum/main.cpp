class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ret = 0;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i - 1] >= nums[i]) {
                sum = 0;
            }
            sum += nums[i];
            ret = std::max(ret, sum);
        }

        return ret;
    }
};
