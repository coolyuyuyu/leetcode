class Solution {
public:
    int maxScore(string s) {
        int ret = 0;
        for (int i = 0, cntLft0 = 0, cntRht1 = std::count(s.begin(), s.end(), '1'); i + 1 < s.size(); ++i) {
            cntLft0 += (s[i] == '0' ? 1 : 0);
            cntRht1 -= (s[i] == '1' ? 1 : 0);
            ret = std::max(ret, cntLft0 + cntRht1);
        }

        return ret;
    }
};
