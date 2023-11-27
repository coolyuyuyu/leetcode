class Solution {
public:
    // Time: O(logN)
    int bsearch(const vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }

    // Time: O(logN)
    int stdlib(const vector<int>& nums, int target) {
        return std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), target));
    }

    int searchInsert(vector<int>& nums, int target) {
        //return bsearch(nums, target);
        return stdlib(nums, target);
    }
};
