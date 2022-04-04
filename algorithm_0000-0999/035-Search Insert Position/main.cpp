class Solution {
public:
    size_t searchInsert_BruteForce(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); ++i) {
            if (target <= nums[i]) {
                return i;
            }
        }

        return nums.size();
    }

    size_t searchInsert_BinarySearch(vector<int>& nums, int target) {
        size_t lo = 0, hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        assert(lo == hi);

        return lo;
    }

    int searchInsert(vector<int>& nums, int target) {
        //return searchInsert_BruteForce(nums, target);
        return searchInsert_BinarySearch(nums, target);
    }
};