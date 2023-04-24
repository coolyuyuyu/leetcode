class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for (int i = nums.size(); 2 < i--;) {
            if (nums[i] < (nums[i - 2] + nums[i - 1])) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }

        return 0;
    }
};
