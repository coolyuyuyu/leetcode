class Solution {
public:
    size_t searchInsert(vector<int>& nums, int target) {
        size_t lo = 0;
        size_t hi = nums.size();

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
        return hi;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        size_t index = searchInsert(arr, x);
        size_t first = (k <= index ? index - k : 0);
        size_t last = (arr.size() <= index + k ? arr.size() : index + k);
        while ((last - first) > k) {
            if (x - arr[first] <= arr[last - 1] - x) {
                last -= 1;
            }
            else {
                first += 1;
            }
        }

        vector<int> ans;
        for (size_t i = first; i < last; ++i) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};