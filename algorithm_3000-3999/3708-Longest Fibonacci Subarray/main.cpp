class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int ret = std::min(n, 2);
        for (int i = 0; i + 2 < n;) {
            int j = i + 2;
            while (j < n && nums[j - 2] + nums[j - 1] == nums[j]) {
                ++j;
            }
            ret = std::max(ret, j - i);
            i = j - 1;
        }

        return ret;
    }
};
