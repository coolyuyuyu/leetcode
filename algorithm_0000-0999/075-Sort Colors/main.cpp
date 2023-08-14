class Solution {
public:
    void sortColors(vector<int>& nums) {
        // quick select
        int i = 0, j = nums.size() - 1, x = 0;
        while (x <= j) {
            if (nums[x] == 0) {
                std::swap(nums[i], nums[x]);
                ++i;
                ++x;
            }
            else if (nums[x] == 1) {
                ++x;
            }
            else {
                std::swap(nums[x], nums[j]);
                --j;
            }
        }
    }
};
