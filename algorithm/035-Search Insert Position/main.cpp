class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lft = 0, rht = nums.size();
        while (lft < rht) {
            int mid = lft + (rht - lft) / 2;
            if (target <= nums[mid]) {
                rht = mid;
            }
            else {
                lft = mid + 1;
            }
        }

        return lft;
    }
};