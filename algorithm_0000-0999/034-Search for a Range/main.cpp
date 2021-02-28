class Solution {
public:
    int searchFirst(vector<int> nums, int target) {
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

    vector<int> searchRange(vector<int>& nums, int target) {
        int index = searchFirst(nums, target);
        if (index < nums.size() && nums[index] == target) {
            return{index, searchFirst(nums, target + 1) - 1};
        }
        else {
            return{-1, -1};
        }
    }
};