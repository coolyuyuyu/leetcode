class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        assert(!nums.empty());

        int minNum = nums[0], maxDiff = -1;
        for (size_t i = 1; i < nums.size(); ++i) {
            maxDiff = max(maxDiff, nums[i] - minNum);
            minNum = min(minNum, nums[i]);
        }

        return maxDiff == 0 ? -1: maxDiff;
    }
};
