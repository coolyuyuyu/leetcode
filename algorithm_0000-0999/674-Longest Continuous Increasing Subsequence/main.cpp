class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        assert(!nums.empty());

        size_t maxLen = 0;
        for (size_t len = 1, i = 1; i <= nums.size(); ++i) {
            int cur = (i == nums.size() ? nums.back() : nums[i]);
            if (nums[i - 1] < cur) {
                ++len;
            }
            else {
                maxLen = std::max(maxLen, len);
                len = 1;
            }
        }

        return maxLen;
    }
};
