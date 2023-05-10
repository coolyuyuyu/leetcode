class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        size_t i;
        for (i = nums.size(); 1 < i--;) {
            if (nums[i - 1] < nums[i]) {
                break;
            }
        }
        if (i-- == 0) {
            std::reverse(nums.begin(), nums.end());
        }
        else {
            size_t j;
            for (j = nums.size(); 0 < j--;) {
                if (nums[i] < nums[j]) {
                    break;
                }
            }
            std::swap(nums[i], nums[j]);
            std::sort(nums.begin() + i + 1, nums.end());
        }
    }
};
