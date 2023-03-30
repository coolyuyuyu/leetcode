class Solution {
public:
    typedef unsigned char uchar;

    bool isScramble(const string& s1, uchar idx1, const string& s2, uchar idx2, uchar n) {
        bool allSame = true;
        array<uchar, 26> cnts; cnts.fill(0);
        for (uchar i = 0; i < n; ++i) {
            if (allSame && s1[idx1 + i] != s2[idx2 + i]) {
                allSame = false;
            }
            ++cnts[s1[idx1 + i] - 'a'];
            --cnts[s2[idx2 + i] - 'a'];
        }
        if (allSame) {
            return true;
        }
        if (!std::all_of(cnts.begin(), cnts.end(), [](uchar cnt){ return cnt == 0; })) {
            return false;
        }

        for (uchar i = 1; i < n; ++i) {
            if ((isScramble(s1, idx1, s2, idx2, i) && isScramble(s1, idx1 + i, s2, idx2 + i, n - i)) ||
                (isScramble(s1, idx1, s2, idx2 + n - i, i) && isScramble(s1, idx1 + i, s2, idx2, n - i))) {
                return true;
            }
        }

        return false;
    }

    bool isScramble_memo(const string& s1, uchar idx1, const string& s2, uchar idx2, uchar n, map<tuple<uchar, uchar, uchar>, bool>& cache) {
        if (cache.find({idx1, idx2, n}) != cache.end()) {
            return cache[{idx1, idx2, n}];
        }

        bool allSame = true;
        array<uchar, 26> cnts; cnts.fill(0);
        for (uchar i = 0; i < n; ++i) {
            if (allSame && s1[idx1 + i] != s2[idx2 + i]) {
                allSame = false;
            }
            ++cnts[s1[idx1 + i] - 'a'];
            --cnts[s2[idx2 + i] - 'a'];
        }
        if (allSame) {
            return cache[{idx1, idx2, n}] = true;
        }
        if (!std::all_of(cnts.begin(), cnts.end(), [](uchar cnt){ return cnt == 0; })) {
            return cache[{idx1, idx2, n}] = false;
        }

        for (uchar i = 1; i < n; ++i) {
            if ((isScramble_memo(s1, idx1, s2, idx2, i, cache) && isScramble_memo(s1, idx1 + i, s2, idx2 + i, n - i, cache)) ||
                (isScramble_memo(s1, idx1, s2, idx2 + n - i, i, cache) && isScramble_memo(s1, idx1 + i, s2, idx2, n - i, cache))) {
                return cache[{idx1, idx2, n}] = true;
            }
        }

        return cache[{idx1, idx2, n}] = false;
    }

    bool isScramble(string s1, string s2) {
        //return isScramble(s1, 0, s2, 0, s1.size());

        map<tuple<uchar, uchar, uchar>, bool> cache;
        return isScramble_memo(s1, 0, s2, 0, s1.size(), cache);
    }
};
