class Solution {
public:
    bool search(vector<int>& nums, int target) {
        size_t lo = 0, hi = nums.size() - 1;
        while (hi > 0 && nums[hi] == nums[0]) {
            --hi;
        }
        for (; lo <= hi;) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) { return true; }
            if ((nums[0] <= nums[mid]) == (nums[0] <= target)) { 
                if (nums[mid] <= target) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            else if (nums[0] <= target) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return false;
    }
};
