class Solution {
public:
    int M = 1e9 + 7;

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int comb[n][k];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                comb[i][j] = 0;
            }
        }
        comb[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= min(i, k - 1); ++j) {
                comb[i][j] = (0L + comb[i - 1][j - 1] + comb[i - 1][j]) % M;
                comb[i][j] %= M;
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                ret += (1L * nums[i] * comb[i][j]) % M;
                ret %= M;
                ret += (1L * nums[i] * comb[n - i - 1][j]) %M;
                ret %= M;
            }
        }

        return ret;
    }
};
