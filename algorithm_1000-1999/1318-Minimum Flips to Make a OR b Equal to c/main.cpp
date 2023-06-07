class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ret = 0;
        for (int i = 0; i < 32; ++i, a >>= 1, b >>= 1, c >>= 1) {
            if (c & 1) {
                if ((a & 1) == 0 && (b & 1) == 0) {
                    ++ret;
                }
            }
            else {
                if (a & 1) {
                    ++ret;
                }
                if (b & 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
