class Solution {
public:
    int findMin(vector<int>& nums) {
        for (size_t lo = 0, hi = nums.size() - 1; lo < hi;) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[lo] < nums[hi]) {
                return nums[lo];
            }
            else if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            else if (nums[lo] > nums[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        assert(nums.size() == 1);
        return nums[0];
    }
};
