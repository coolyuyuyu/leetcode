class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ret = 0;
        for (int lft = 0, rht = 0, n = nums.size(); lft < n; ++lft) {
            while (lft == rht || (rht < n && nums[rht - 1] != nums[rht])) {
                ++rht;
            }

            ret += rht - lft;
        }

        return ret;
    }
};
