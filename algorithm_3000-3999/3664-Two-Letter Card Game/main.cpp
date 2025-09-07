class Solution {
public:
    int score(vector<string>& cards, char x) {
        int doubleX = 0;
        vector<int> cnt1s(10, 0), cnt2s(10, 0);
        for (const string& card : cards) {
            char c1 = card[0], c2 = card[1];
            if (c1 != x && c2 != x) { continue; }
            if (c1 == x && c2 == x) { ++doubleX; }
            else if (c1 == x) { ++cnt2s[c2 - 'a']; }
            else { ++cnt1s[c1 - 'a'];}
        }

        int total1 = 0, maxCnt1 = 0;
        for (int cnt : cnt1s) {
            total1 += cnt;
            maxCnt1 = std::max(maxCnt1, cnt);
        }
        int total2 = 0, maxCnt2 = 0;
        for (int cnt : cnt2s) {
            total2 += cnt;
            maxCnt2 = std::max(maxCnt2, cnt);
        }

        int ret = 0;
        for (int extraCnt1 = 0, extraCnt2 = doubleX; extraCnt1 <= doubleX; ++extraCnt1, --extraCnt2) {
            int score1 = std::min((total1 + extraCnt1) / 2, total1 + extraCnt1 - std::max(maxCnt1, extraCnt1));
            int score2 = std::min((total2 + extraCnt2) / 2, total2 + extraCnt2 - std::max(maxCnt2, extraCnt2));
            ret = std::max(ret, score1 + score2);
        }

        return ret;
    }
};
