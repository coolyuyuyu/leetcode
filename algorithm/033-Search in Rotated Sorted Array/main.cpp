class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lft = 0, rht = nums.size() - 1;
        while (lft <= rht) {
            int mid = lft + (rht - lft) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else {
                if (nums[lft] <= nums[mid]) {
                    if (nums[lft] <= target && target <= nums[mid]) {
                        rht = mid - 1;
                    }
                    else {
                        lft = mid + 1;
                    }
                }
                else {
                    if (nums[mid] <= target && target <= nums[rht]) {
                        lft = mid + 1;
                    }
                    else {
                        rht = mid - 1;
                    }
                }
            }
        }

        return -1;
    }
};