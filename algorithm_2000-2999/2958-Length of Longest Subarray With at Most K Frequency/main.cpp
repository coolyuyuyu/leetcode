class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> cnts;

        int ret = 0;
        for (int lft = 0, rht = 0; rht < n; ++lft) {
            for (; rht < n && cnts[nums[rht]] < k; ++rht) {
                ++cnts[nums[rht]];
            }

            ret = std::max(ret, rht - lft);

            --cnts[nums[lft]];
        }

        return ret;
    }
};
