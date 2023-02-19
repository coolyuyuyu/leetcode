class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = nums[0], b = nums[1], x = nums[2], y = nums[n - 3], c = nums[n - 2], d = nums[n - 1];
        return std::min({y - a, d - x, c - b});
    }
};
