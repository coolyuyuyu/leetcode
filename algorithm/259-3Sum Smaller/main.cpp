class Solution {
public:

    size_t searchInsert(const vector<int> nums, size_t lo, int target) {
        size_t hi = nums.size();
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

    size_t twoSumSmaller1(const vector<int>& nums, size_t lo, int target) {
        size_t sum = 0;
        for (size_t i = lo; i + 1 < nums.size(); ++i) {
            size_t index = searchInsert(nums, i + 1, target - nums[i]);
            sum += (index - (i + 1));
        }

        return sum;
    }

    size_t twoSumSmaller2(const vector<int>& nums, size_t lo, int target) {
        size_t sum = 0;
        size_t hi = nums.size();
        while (lo + 1 < hi) {
            if (nums[lo] + nums[hi - 1] < target) {
                sum += (hi - lo - 1);
                ++lo;
            }
            else {
                --hi;
            }
        }

        return sum;
    }

    size_t threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        size_t sum = 0;
        for (size_t i = 0; i + 2 < nums.size(); ++i) {
            //sum += twoSumSmaller1(nums, i + 1, target - nums[i]);

            sum += twoSumSmaller2(nums, i + 1, target - nums[i]);
        }

        return sum;
    }
};