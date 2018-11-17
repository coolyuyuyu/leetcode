class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        size_t lft = 0;
        for (lft; seats[lft] != 1; ++lft)
            ;
        size_t lftEmptyCnt = lft;

        size_t rht = seats.size() - 1;
        for (rht; seats[rht] != 1; --rht)
            ;
        size_t rhtEmptyCnt = seats.size() - rht - 1;

        size_t maxMiddleEmptyCnt = 0;
        for (size_t lastNonEmptyIdx = lft, idx = lft + 1; idx <= rht; ++idx) {
            if (seats[idx] == 1) {
                size_t emptyCnt = idx - lastNonEmptyIdx - 1;
                if (maxMiddleEmptyCnt < emptyCnt) {
                    maxMiddleEmptyCnt = emptyCnt;
                }

                lastNonEmptyIdx = idx;
            }
        }

        size_t maxDist = max(lftEmptyCnt, rhtEmptyCnt);
        maxDist = max(maxDist, (maxMiddleEmptyCnt + 1) / 2);
        return maxDist;
    }
};