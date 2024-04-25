class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0, std::bit_or<int>());

        int ret = 0;
        for (int s = 1; s < (1 << n); ++s) {
            int t = 0;
            for (int ss = s, i = 0; ss; ss >>= 1, ++i) {
                if (ss & 1) {
                    t |= nums[i];
                }
            }
            if (t == sum) {
                ++ret;
            }
        }

        return ret;
    }
};
