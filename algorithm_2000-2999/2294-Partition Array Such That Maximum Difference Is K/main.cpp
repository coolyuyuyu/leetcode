class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int preNum = INT_MIN / 2, i = 0; i < nums.size(); ++i) {
            if (nums[i] - preNum > k) {
                preNum = nums[i];
                ++ret;
            }
        }

        return ret;
    }
};
