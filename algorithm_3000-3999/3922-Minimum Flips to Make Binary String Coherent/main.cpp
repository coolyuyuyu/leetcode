class Solution {
public:
    int minFlips(string s) {
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) {
            (c == '0' ? ++cnt0 : ++cnt1);
        }

        int ret = s.size();

        // all 0
        ret = std::min(ret, cnt1);

        // all 1
        ret = std::min(ret, cnt0);

        // at most one 1
        ret = std::min(ret, std::max(0, cnt1 - 1));

        // pattern 1000...0001
        if (s.size() > 2) {
            int x = 0;
            if (s.front() == '0') { ++x; }
            for (int i = 1; i + 1 < s.size(); ++i) {
                if (s[i] == '1') { ++x; }
            }
            if (s.back() == '0') { ++x; }
            ret = std::min(ret, x);
        }

        return ret;
    }
};
