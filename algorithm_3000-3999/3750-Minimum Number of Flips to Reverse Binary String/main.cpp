class Solution {
public:
    int minimumFlips(int n) {
        int m = 0;
        for (int num = n; num; num >>= 1) {
            m = (m <<= 1) | (num & 1);
        }

        int ret = 0;
        for (; n || m; n >>= 1, m >>= 1) {
            ret += ((n & 1) != (m & 1));
        }

        return ret;
    }
};
