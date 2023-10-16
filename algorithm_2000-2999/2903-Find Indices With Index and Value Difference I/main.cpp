class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        for (int lft = 0; lft < n; ++lft) {
            for (int rht = lft + indexDifference; rht < n; ++rht) {
                if (abs(nums[lft] - nums[rht]) >= valueDifference) {
                    return {lft, rht};
                }
            }
        }

        return {-1, -1};
    }
};
