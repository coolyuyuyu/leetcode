class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ret;
        for (int i = 0, n = nums.size(); i <= n; ++i) {
            int lft = (i == 0 ? lower : nums[i - 1] + 1);
            int rht = (i == n ? upper : nums[i] - 1);
            if (lft <= rht) {
                ret.push_back({lft, rht});
            }
        }

        return ret;
    }
};
