class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }
        int numDistinct = cnts.size();
        cnts.clear();

        int ret = 0;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            for (; rht < n && cnts.size() < numDistinct; ++rht) {
                ++cnts[nums[rht]];
            }

            if (cnts.size() == numDistinct) {
                ret += (n - rht + 1);
            }

            if (--cnts[nums[lft]] == 0) {
                cnts.erase(nums[lft]);
            }
        }

        return ret;
    }
};
