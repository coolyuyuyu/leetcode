class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();

        int rhtMax[n], rhtMaxIdx[n];
        int rhtMin[n], rhtMinIdx[n];
        rhtMax[n - 1] = rhtMin[n - 1] = nums[n - 1];
        rhtMaxIdx[n - 1] = rhtMinIdx[n - 1] = n - 1;
        for (int i = n - 1; 0 < i--;) {
            if (nums[i] >= rhtMax[i + 1]) {
                rhtMax[i] = nums[i];
                rhtMaxIdx[i] = i;
            }
            else {
                rhtMax[i] = rhtMax[i + 1];
                rhtMaxIdx[i] = rhtMaxIdx[i + 1];
            }
            if (nums[i] <= rhtMin[i + 1]) {
                rhtMin[i] = nums[i];
                rhtMinIdx[i] = i;
            }
            else {
                rhtMin[i] = rhtMin[i + 1];
                rhtMinIdx[i] = rhtMinIdx[i + 1];
            }
        }

        for (int lft = 0, rht = lft + indexDifference; rht < n; ++lft, ++rht) {
            if (abs(nums[lft] - rhtMax[rht]) >= valueDifference) {
                return {lft, rhtMaxIdx[rht]};
            }
            if (abs(nums[lft] - rhtMin[rht]) >= valueDifference) {
                return {lft, rhtMinIdx[rht]};
            }
        }

        return {-1, -1};
    }
};
