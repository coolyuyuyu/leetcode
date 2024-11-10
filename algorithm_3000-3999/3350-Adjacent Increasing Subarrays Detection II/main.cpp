class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ret = 0;
        for (int i = 0, n = nums.size(), preLen = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j]) {
                ++j;
            }
            int len = j - i;

            ret = std::max(ret, std::min(preLen, len));
            ret = std::max(ret, len / 2);

            i = j;
            preLen = len;
        }

        return ret;
    }
};
