class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lft = 0;
        int rht = nums.size() - 1;
        while (lft <= rht) {
            int mid = lft + (rht - lft) / 2;
            if (nums[mid] < target) {
                lft = mid + 1;
            }
            else if (nums[mid] == target) {
                return mid;
            }
            else {
                rht = mid - 1;
            }
        }
        return lft;
    }
};