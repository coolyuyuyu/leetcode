class Solution {
public:
    int minOperations(int k) {
        int ret = k;
        for (int i = 1; i <= k; ++i) {
            int incCnt = i - 1;
            int dupCnt = (k + (i - 1)) / i - 1;
            ret = std::min(ret, incCnt + dupCnt);
        }

        return ret;
    }
};
