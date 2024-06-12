class Solution {
public:
    void sortColors(vector<int>& nums) {
        // quick select
        for (int i = 0, j = nums.size() - 1, x = 0; x <= j;) {
            switch (nums[x]) {
                case 0:
                    std::swap(nums[i], nums[x]);
                    ++i, ++x;
                    break;
                case 1:
                    ++x;
                    break;
                case 2:
                    std::swap(nums[x], nums[j]);
                    --j;
                    break;
            }
        }
    }
};
