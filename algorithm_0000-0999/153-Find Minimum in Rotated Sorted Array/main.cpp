class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() < nums.back()) {
            return nums[0];
        }

        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[0] <= nums[mid]) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return nums[lo];
    }
};
