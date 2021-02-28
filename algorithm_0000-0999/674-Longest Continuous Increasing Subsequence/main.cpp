class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        size_t maxLen = 0;
        size_t len = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ++len;
            }
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }

        }
        maxLen = max(maxLen, len);

        return maxLen;
    }
};