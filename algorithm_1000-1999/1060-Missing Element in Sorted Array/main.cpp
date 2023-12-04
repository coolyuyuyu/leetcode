class Solution {
public:
    // Time: O(N)
    int lsearch(const vector<int>& nums, int k) {
        for (int num : nums) {
            if (num <= k) {
                ++k;
            }
            else {
                break;
            }
        }

        return k;
    }

    // Time: O(logN)
    int bsearch(const vector<int>& nums, int k) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] - mid - 1 < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo + k;
    }

    int missingElement(vector<int>& nums, int k) {
        //return lsearch(nums, nums.front() + k - 1);
        return bsearch(nums, nums.front() + k - 1);
    }
};
