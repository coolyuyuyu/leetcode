class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;
        for (size_t i = k - 1; i < nums.size(); ++i) {
            minDiff = std::min(minDiff, nums[i] - nums[i - k + 1]);
        }

        return minDiff;
    }
};
