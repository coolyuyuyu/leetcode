class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int busyCnt = startTime.size(), freeCnt = startTime.size() + 1;

        int frees[freeCnt], freesMx2Rht[freeCnt];
        for (int i = freeCnt; 0 < i--;) {
            frees[i] = (i < busyCnt ? startTime[i] : eventTime) - (i > 0 ? endTime[i - 1] : 0);
            freesMx2Rht[i] = std::max(i + 1 < freeCnt ? freesMx2Rht[i + 1] : 0, frees[i]);
        }

        int ret = 0;
        for (int i = 0, lftFreeMx = 0, rhtFreeMx; i < busyCnt; ++i) {
            int busy = endTime[i] - startTime[i];

            lftFreeMx = std::max(lftFreeMx, i > 0 ? frees[i - 1] : 0);
            rhtFreeMx = i + 2 < freeCnt ? freesMx2Rht[i + 2] : 0;
            int moveoutFree = (i + 1 < busyCnt ? startTime[i + 1] : eventTime) - (i > 0 ? endTime[i - 1] : 0);
            if (busy <= std::max(lftFreeMx, rhtFreeMx)) {
                ret = std::max(ret, moveoutFree);
            }

            int pulloffFree = moveoutFree - busy;
            ret = std::max(ret, pulloffFree);
        }

        return ret;
    }
};
