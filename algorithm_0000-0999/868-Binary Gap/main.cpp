class Solution {
public:
    int binaryGap(int n) {
        int ret = 0;
        for (int cur = 0, pre = 32; n; ++cur, n >>= 1) {
            if (n & 1) {
                ret = std::max(ret, cur - pre);
                pre = cur;
            }
        }

        return ret;
    }
};