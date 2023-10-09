class Solution {
public:
    int M = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> cnts(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) {
                    ++cnts[i];
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < k; ++j) {
            long long x = 0;
            for (int i = 0; i < 32; ++i) {
                if (cnts[i]) {
                    x |= (1 << i);
                    --cnts[i];
                }
            }
            ret += (x * x) % M;
            ret %= M;
        }

        return ret;
    }
};
