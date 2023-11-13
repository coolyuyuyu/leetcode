class Solution {
public:
    typedef unsigned long long ULL;
    int countDistinct(string s) {
        int n = s.size();

        ULL base = 26;

        int ret = 0;
        ULL power = 1;
        for (int len = 1; len <= n; ++len, power *= base) {
            unordered_set<ULL> hashs;
            ULL hash = 0;
            for (int i = 0; i < n; ++i) {
                if (len <= i) {
                    hash -= (s[i - len] - 'a') * power;
                }
                hash = hash * base + s[i] - 'a';

                if (len - 1 <= i) {
                    hashs.insert(hash);
                }
            }

            ret += hashs.size();
        }

        return ret;
    }
};
