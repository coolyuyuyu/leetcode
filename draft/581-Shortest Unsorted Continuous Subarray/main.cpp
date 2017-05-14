class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> sorted(nums);
        sort(nums.begin(), nums.end());

        int bgn = 0;
        for (bgn = 0; bgn < nums.size(); ++bgn) {
            if (nums[bgn] != sorted[bgn]) {
                break;
            }
        }

        if (bgn == nums.size()) {
            return 0;
        }

        int end = nums.size() - 1;
        for (; (end - 1) >= 0; --end) {
            if (nums[end] != sorted[end]) {
                break;
            }
        }

        return end - bgn + 1;
    }
};