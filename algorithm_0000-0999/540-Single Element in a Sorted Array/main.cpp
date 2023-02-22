class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        size_t lo = 0, hi = nums.size() - 1;
        while (1 < (hi - lo)) {
            size_t mid = lo + (hi - lo) / 2;
            if (mid & 1) {
                if (nums[mid - 1] == nums[mid]) {
                    lo = mid + 1;
                    }
                else {
                    hi = mid - 1;
                }
            }
            else {
                if (nums[mid - 1] == nums[mid]) {
                    hi = mid;
                }
                else {
                    lo = mid;
                }
            }
        }

        return nums[lo];

    }
};

// [1]
//     1
// [3]
//     1 2 2
//     2 2 3 
// [5]
//     1 1 2 3 3
//     1 2 2 3 3
//     1 1 2 2 3
