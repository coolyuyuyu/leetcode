class Solution {
public:
    int M = 1e9 + 7;

    int numSub(string s) {
        int ret = 0;
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (s[i] != '1') { continue; }

            int j = i + 1;
            while (j < n && s[j] == '1') {
                ++j;
            }

            int cnt = j - i;
            ret += (1L * (cnt + 1) * cnt / 2) % M;
            ret %= M;

            i = j - 1;
        }

        return ret;
    }
};
