class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;

        int ret = n;
        for (int i = 0, ret1 = 0, ret2 = 0, parity1 = 0, parity2 = 1; i < s.size(); ++i, parity1 = 1 - parity1, parity2 = 1 - parity2) {
            ret1 += (s[i] - '0') != parity1;
            ret2 += (s[i] - '0') != parity2;
            if (i + 1 >= n) {
                ret = std::min({ret, ret1, ret2});

                int p1 = n & 1 ? (parity1) : (1 - parity1);
                int p2 = n & 1 ? (parity2) : (1 - parity2);
                ret1 -= (s[i + 1 - n] - '0') != p1;
                ret2 -= (s[i + 1 - n] - '0') != p2;
            }
        }

        return ret;
    }
};
