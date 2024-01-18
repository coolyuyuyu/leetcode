class Solution {
public:
    int closestFair(int n) {
        std::function<int(int, int)> f = [](int lftNum, int rhtDigitCnt) {
            int diff = 0;
            for (int x = lftNum; x; x /= 10) {
                x & 1 ? ++diff : --diff;
            }
            if ((diff + rhtDigitCnt) & 1) { return -1; }

            int rhtE = (rhtDigitCnt - diff) / 2;
            int rhtO = (rhtDigitCnt + diff) / 2;
            if (rhtE < 0 || rhtO < 0) { return -1; }

            int ret = lftNum;
            for (int i = 0; i < rhtO; ++i) {
                ret *= 10;
            }
            for (int i = 0; i < rhtE; ++i) {
                ret = ret * 10 + 1;
            }

            return ret;
        };

        int ret = f(n, 0);
        if (ret > 0) { return ret; }
        for (int x = n, i = 0; true; x /= 10, ++i) {
            ret = f(x + 1, i);
            if (ret > 0) { break;}
            ret = f(x + 2, i);
            if (ret > 0) { break;}
        }

        return ret;
    }
};
