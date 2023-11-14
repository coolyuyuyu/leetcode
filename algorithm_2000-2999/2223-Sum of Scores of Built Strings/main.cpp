class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();

        typedef unsigned long long ULL;
        ULL base = 26;

        ULL hashs[n], powers[n];
        hashs[0] = s[0] - 'a';
        powers[0] = 1;
        for (int i = 1; i < n; ++i) {
            hashs[i] = hashs[i - 1] * base + s[i] - 'a';
            powers[i] = powers[i - 1] * base;
        }

        std::function<ULL(int, int)> computeHash = [&](int lo, int hi) {
            if (hi < lo) { return 0ULL; }
            if (lo == 0) { return hashs[hi]; }
            return hashs[hi] - hashs[lo - 1] * powers[hi - lo + 1];
        };

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            int lo = 0, hi = n - i;
            while (lo < hi) {
                int mid = hi - (hi - lo) / 2;
                if (computeHash(0, mid - 1) == computeHash(i, i + mid - 1)) {
                    lo = mid;
                }
                else {
                    hi = mid - 1;
                }
            }

            ret += lo;
        }

        return ret;
    }
};
