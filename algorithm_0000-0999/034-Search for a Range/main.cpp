class Solution {
public:
    vector<int> bsearch(vector<int>& nums, int target) {
        int lo, hi;

        for (lo = 0, hi = nums.size(); lo < hi;) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        if (lo == nums.size() || nums[lo] != target) {
            return {-1, -1};
        }
        int lft = lo;

        for (hi = nums.size() - 1; lo < hi;) {
            int mid = hi - (hi - lo) / 2;
            if (nums[mid] <= target) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }
        int rht = lo;

        return {lft, rht};
    }

    vector<int> bsearch_stdlib(vector<int>& nums, int target) {
        auto itr = std::lower_bound(nums.begin(), nums.end(), target);
        if (itr == nums.end() || *itr != target) { return {-1, -1}; };

        int l = std::distance(nums.begin(), itr);
        int r = std::distance(nums.begin(), std::prev(std::upper_bound(itr, nums.end(), target)));
        return {l, r};
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        //return bsearch(nums, target);
        return bsearch_stdlib(nums, target);
    }
};
