class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() <= nums.back()) {
            return nums.front();
        }

        for (size_t lo = 0, hi = nums.size() - 1; lo < hi;) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            else if (nums[lo] > nums[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        assert(false);
        return 0;
    }
};
