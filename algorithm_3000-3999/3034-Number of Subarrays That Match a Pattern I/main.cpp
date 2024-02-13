class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = nums.size(), n = pattern.size();

        int ret = 0;
        for (int i = 0; i + n < m; ++i) {
            bool match = true;
            for (int k = 0; k < n; ++k) {
                if (nums[i + k] < nums[i + k + 1]) {
                    if (pattern[k] != 1) { match = false; break; }
                }
                else if (nums[i + k] == nums[i + k + 1]) {
                    if (pattern[k] != 0) { match = false; break; }
                }
                else {
                    if (pattern[k] != -1) { match = false; break; }
                }
            }
            if (match) {
                ++ret;
            }
        }

        return ret;
    }
};
