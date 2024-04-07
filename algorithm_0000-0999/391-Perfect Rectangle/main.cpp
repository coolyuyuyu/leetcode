class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long sum = 0;
        int lft = INT_MAX, btm = INT_MAX, rht = INT_MIN, top = INT_MIN;
        map<pair<int, int>, int> xy2cnt;
        for (const auto& rect : rectangles) {
            int l = rect[0], b = rect[1], r = rect[2], t = rect[3];

            lft = std::min(lft, l);
            btm = std::min(btm, b);
            rht = std::max(rht, r);
            top = std::max(top, t);

            sum += 1LL * (r - l) * (t - b);

            ++xy2cnt[{l, b}];
            ++xy2cnt[{l, t}];
            ++xy2cnt[{r, b}];
            ++xy2cnt[{r, t}];
        }

        int uniqueCnt = 0;
        int otherCnt = 0;
        for (const auto& [xy, cnt] : xy2cnt) {
            if ((cnt % 2) == 0) { ; }
            else if (cnt == 1) { ++uniqueCnt; }
            else { ++otherCnt; }
        }
        if (uniqueCnt != 4) {
            return false;
        }
        else if (otherCnt != 0) {
            return false;
        }
        else if (xy2cnt[{lft, btm}] != 1 || xy2cnt[{lft, top}] != 1 || xy2cnt[{rht, btm}] != 1 || xy2cnt[{rht, top}] != 1) {
            return false;
        }

        return sum == (1LL * (rht - lft) * (top - btm));
    }
};
