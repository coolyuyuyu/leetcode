class Solution {
public:
    int minPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int i = 0; i * 2 < nums.size(); ++i) {
            ret = std::max(ret, nums[i] + nums[nums.size() - i - 1]);
        }

        return ret;
    }
};
