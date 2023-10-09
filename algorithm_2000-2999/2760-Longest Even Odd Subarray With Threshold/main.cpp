class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();

        int ret = 0;
        for (int l = 0; l < n; ++l) {
            if (nums[l] % 2 != 0 || threshold < nums[l] ) { continue; }
            int len = 1;
            while (l + len < n && nums[l + len] <= threshold && nums[l + len - 1] % 2 != nums[l + len] % 2) {
                ++len;
            }
            ret = std::max(ret, len);
        }

        return ret;
    }
};
