class Solution {
public:
    size_t findTargetSumWaysDfs(vector<int>& nums, size_t level, int target, const pair<int, int>& range) {
        if (nums.size() <= level) {
            return target == 0 ? 1 : 0;
        }

        if (target < range.first || range.second < target) {
            return 0;
        }

        int num = nums[level];
        pair<size_t, size_t> rangeNew = {range.first + num, range.second - num};
        size_t countPlus = findTargetSumWaysDfs(nums, level + 1, target - num, rangeNew);
        size_t countMinus = findTargetSumWaysDfs(nums, level + 1, target + num, rangeNew);
        return countPlus + countMinus;
    }

    size_t findTargetSumWays(vector<int>& nums, int S) {
        int total = accumulate(nums.begin(), nums.end(), int(0));
        return findTargetSumWaysDfs(nums, 0, S, {-total, total});
    }
};