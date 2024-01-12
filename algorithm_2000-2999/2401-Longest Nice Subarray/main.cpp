class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int i = 0, j = 0, cnt = 0; j < n; ++i) {
            for (; j < n && ((cnt & nums[j]) == 0); ++j) {
                cnt |= nums[j];
            }

            ret = std::max(ret, j - i);

            cnt &= ~nums[i];
        }

        return ret;
    }
};
