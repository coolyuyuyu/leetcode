class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxVal = INT_MIN, maxLen = 0;
        for (int lft = 0, rht = 0; lft < n;) {
            for (; rht < n; ++rht) {
                if (nums[lft] != nums[rht]) {
                    break;
                }
            }

            int len = rht - lft;
            if (nums[lft] > maxVal) {
                maxVal = nums[lft];
                maxLen = len;
            }
            else if (nums[lft] == maxVal) {
                maxLen = std::max(maxLen, len);
            }

            lft = rht;
        }

        return maxLen;
    }
};
