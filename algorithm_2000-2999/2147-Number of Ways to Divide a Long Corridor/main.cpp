class Solution {
public:
    int M = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();

        long long ret = 1;
        int seatCnt = 0;
        for (int i = 0, seatIdx = -1; i < n; ++i) {
            if (corridor[i] == 'P') { continue; }
            ++seatCnt;

            if (seatCnt >= 3 && (seatCnt % 2) == 1) {
                ret *= i - seatIdx;
                ret %= M;
            }

            seatIdx = i;
        }
        if (seatCnt == 0) { return 0; }
        else if (seatCnt % 2 == 1) { return 0; }

        return ret;
    }
};
