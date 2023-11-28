class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
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
