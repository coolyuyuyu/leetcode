class Solution {
public:
    int M = 1e9 + 7;

    int sumOfBlocks(int n) {
        int ret = 0;
        for (int i = 1, cur = 1; i <= n; ++i) {
            int prod = 1;
            for (int j = 0; j < i; ++j) {
                prod = 1LL * prod * cur % M;
                prod %= M;
                ++cur;
            }

            ret += prod;
            ret %= M;
        }

        return ret;
    }
};
