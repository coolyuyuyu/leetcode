class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        for (size_t lo = 0, hi = nums.size() - 1; lo <= hi;) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
