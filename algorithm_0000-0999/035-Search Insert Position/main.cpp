class Solution {
public:
    size_t searchInsert(vector<int>& nums, int target) {
        size_t lo = 0;
        size_t hi = nums.size();

        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (target <= nums[mid]) {
                hi = mid;
            }
            else {
                assert(nums[mid] < target);
                lo = mid + 1;
            }
        }

        assert(lo == hi);
        return hi;
    }
};