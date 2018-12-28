class Solution {
public:
    size_t searchInsert(const vector<int>& nums, int target) {
        size_t lo = 0, hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        assert(nums.empty() ? true : lower <= nums.front() && nums.back() <= upper);
        if (nums.empty()) {
            string range = to_string(lower);
            if (lower != upper) {
                range += "->";
                range += to_string(upper);
            }
            return {range};
        }

        vector<string> ans;

        if (lower < nums.front()) {
            string str = to_string(lower);
            if (lower + 1 < nums.front()) {
                str += "->";
                str += to_string(nums.front() - 1);
            }
            ans.emplace_back(str);
        }

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i] && nums[i - 1] + 1 < nums[i]) {
                string str = to_string(nums[i - 1] + 1);
                if (nums[i - 1] + 1 < nums[i] - 1) {
                    str += "->";
                    str += to_string(nums[i] - 1);
                }
                ans.emplace_back(str);

            }
        }

        if (nums.back() < upper) {
            string str = to_string(nums.back() + 1);
            if (nums.back() + 1 < upper) {
                str += "->";
                str += to_string(upper);
            }
            ans.emplace_back(str);

        }

        return ans;
    }
};