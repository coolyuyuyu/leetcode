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
            else if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                if (mid == 0) {
                    return -1;
                }
                hi = mid - 1;
            }
        }

        return -1;
    }
};
