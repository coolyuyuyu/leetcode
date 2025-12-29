class Solution {
public:
    int M = 1e9 + 7;

    int numberOfWays(string corridor) {
        int seatCnt = 0;
        int ret = 1;
        for (int i = 0, n = corridor.size(), preSeat = -1; i < n; ++i) {
            if (corridor[i] == 'P') { continue; }

            ++seatCnt;
            if (seatCnt >= 3 && (seatCnt & 1)) {
                ret =  1LL * ret * (i - preSeat) % M;
            }

            preSeat = i;
        }
        if (seatCnt == 0) { return 0;}
        if (seatCnt & 1) { return 0; }

        return ret;
    }
};
