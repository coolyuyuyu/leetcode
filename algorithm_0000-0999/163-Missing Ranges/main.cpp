class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<vector<int>> ret;
        for (int i = 0; i <= n; ++i) {
            int pre = (i == 0 ? (lower) : nums[i - 1] + 1);
            int cur = (i == n ? (upper) : nums[i] - 1);
            if (pre <= cur) {
                ret.push_back({pre, cur});
            }
        }

        return ret;
    }
};
