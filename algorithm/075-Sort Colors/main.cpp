class Solution {
public:
    void sortColors(vector<int>& nums) {
        size_t index0 = 0;
        size_t index1 = 0;
        size_t index2 = 0;
        for (int num : nums) {
            switch (num) {
            case 0:
                nums[index2++] = 2;
                nums[index1++] = 1;
                nums[index0++] = 0;
                break;
            case 1:
                nums[index2++] = 2;
                nums[index1++] = 1;
                break;
            case 2:
                ++index2;
                break;
            }
        }
    }
};