class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for (int i = 0, n = nums.size(), preLen = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j]) {
                ++j;
            }
            int len = j - i;

            if (preLen >= k && len >= k) { return true; }
            if (len >= k * 2) { return true; }

            i = j;
            preLen = len;
        }

        return false;
    }
};
