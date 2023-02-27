class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int i = 0, j = (n / 2); i < (n / 2); ++i) {
            while (j < n &&  nums[j] < nums[i] * 2) {
                ++j;
            }
            if (j < n) {
                ret += 2;
                ++j;
            }
        }

        return ret;
    }
};
