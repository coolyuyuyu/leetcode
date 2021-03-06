class Solution {
public:
    size_t searchInsert(vector<int>& nums, int target, size_t lo, size_t hi) {
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (target <= nums[mid]) {
                hi = mid;
            }
            else {
                assert(nums[mid] < target);
                lo = mid + 1;
            }
        }

        assert(lo == hi);
        return lo;
    }

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1, lo = j + 1; j + 1 < nums.size(); ++j, lo = max(j + 1, lo)) {
                lo = searchInsert(nums, nums[i] + nums[j], lo, nums.size());
                count += (lo - j - 1);
            }
        }

        return count;
    }
};