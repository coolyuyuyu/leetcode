class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ret = 0;
        for (int i = 0, n = nums.size(); i < n;) {
            int j = i + 1;
            while (j + 1 < n && nums[i + 1] - nums[i] == nums[j + 1] - nums[j]) {
                ++j;
            }

            int len = j - i + 1;
            ret += (len  - 1) * (len - 2) / 2;

            i = j;
        }

        return ret;
    }
};
