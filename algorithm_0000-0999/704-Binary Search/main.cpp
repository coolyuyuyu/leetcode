class Solution {
public:
    // Possibly OVERFLOW
    int search1(const vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                hi = mid - 1;
            }
            else {
                assert(nums[mid] < target);
                lo = mid + 1;
            }
        }

        return -1;
    }

    // Never overflow
    int search2(const vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        size_t lo = 0;
        size_t hi = nums.size() - 1;
        while (lo <= hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                if (mid == 0) {
                    return -1;
                }
                hi = mid - 1;
            }
            else {
                assert(nums[mid] < target);
                lo = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        //return search1(nums, target);

        return search2(nums, target);
    }
};