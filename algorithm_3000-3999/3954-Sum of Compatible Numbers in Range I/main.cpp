class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ret = 0;
        for (int x = std::max(n - k, 1); x <= n + k; ++x) {
            if ((n & x) == 0) {
                ret += x;
            }
        }

        return ret;
    }
};
