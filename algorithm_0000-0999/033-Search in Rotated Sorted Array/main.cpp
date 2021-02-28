class Solution {
public:
    int search1(const vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else {
                if (nums[lo] <= nums[mid]) {
                    if (nums[lo] <= target && target <= nums[mid]) {
                        hi = mid - 1;
                    }
                    else {
                        lo = mid + 1;
                    }
                }
                else {
                    if (nums[mid] <= target && target <= nums[hi]) {
                        lo = mid + 1;
                    }
                    else {
                        hi = mid - 1;
                    }
                }
            }
        }

        return -1;
    }

    int search2(const vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        size_t lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else {
                if (nums[lo] <= nums[mid]) {
                    if (nums[lo] <= target && target <= nums[mid]) {
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
                    if (nums[mid] <= target && target <= nums[hi]) {
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
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        //return search1(nums, target);

        return search2(nums, target);
    }
};