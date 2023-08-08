class Solution {
public:
    int f1(const vector<int>& nums, int target) {
        for (size_t lo = 0, hi = nums.size() - 1; lo <= hi;) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && target < nums[mid]) {
                    if (mid == 0) {
                        return -1;
                    }
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            else {
                assert(nums[mid] <= nums[hi]);
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                }
                else {
                    if (mid == 0) {
                        return -1;
                    }
                    hi = mid - 1;
                }
            }
        }

        return -1;
    }

    int f2(const vector<int>& nums, int target) {
        for (size_t lo = 0, hi = nums.size() - 1; lo <= hi;) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) { return mid; }
            if ((nums[0] <= nums[mid] && nums[0] <= target) || (nums[0] > nums[mid] && nums[0] > target)) {
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

        return -1;
    }

    int search(vector<int>& nums, int target) {
        //return f1(nums, target);
        return f2(nums, target);
    }
};
