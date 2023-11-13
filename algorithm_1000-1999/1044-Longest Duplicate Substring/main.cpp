class Solution {
public:
    string rollingHash(string s) {
        int n = s.size();

        typedef uint64_t ULL;

        ULL base = 29;
        std::function<int(int)> findRepeatingSubstringOfLen = [&](int len) {
            ULL powOfHiBit = 1;
            for (int i = 1; i < len; ++i) {
                powOfHiBit = powOfHiBit * base;
            }

            unordered_set<ULL> hashs;

            ULL hash = 0;
            for (int i = 0; i < n; ++i) {
                if (i >= len) {
                    hash = (hash - (s[i - len] - 'a') * powOfHiBit);
                }
                hash = hash * base;
                hash = (hash + s[i] - 'a');

                if (i >= len - 1 && hashs.insert(hash).second == false) {
                    return i + 1 - len;
                }
            }

            return -1;
        };

        int lo = 1, hi = n - 1;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (findRepeatingSubstringOfLen(mid) >= 0) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        int idx = findRepeatingSubstringOfLen(lo);
        return idx >= 0 ? s.substr(idx, lo) : "";
    }

    string longestDupSubstring(string s) {
        return rollingHash(s);
    }
};
