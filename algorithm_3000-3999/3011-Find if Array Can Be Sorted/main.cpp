class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for (int i = 0, n = nums.size(), preMax = INT_MIN; i < n;) {
            int cnt = __builtin_popcount(nums[i]);
            int curMin = nums[i], curMax = nums[i];
            int j;
            for (j = i + 1; j < n && __builtin_popcount(nums[j]) == cnt; ++j) {
                curMin = std::min(curMin, nums[j]);
                curMax = std::max(curMax, nums[j]);
            }
            if (preMax > curMin) {
                return false;
            }
            preMax = curMax;

            i = j;
        }

        return true;
    }
};
