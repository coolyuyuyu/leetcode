class Solution {
public:
    size_t findPeakElementLinearSearch(vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                return i - 1;
            }
        }

        return nums.size() - 1;
    }

    size_t findPeakElementBinarySearch(vector<int>& nums) {
        size_t lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            }
            else {
                hi = mid ;
            }
        }

        return lo;
    }

    size_t findPeakElement(vector<int>& nums) {
        assert(!nums.empty());

        //return findPeakElementLinearSearch(nums);

        return findPeakElementBinarySearch(nums);
    }
};