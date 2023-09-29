class Solution {
public:
    typedef unsigned char uchar;

    // TLE
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

    bool btmupDp(string s1, string s2) {
        int n = s1.size();

        // dp[i][j][len]: whether s1[i:i+len-1] is a scramble of s2[j:j+len-1]
        bool dp[n][n][n + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; (i + len) <= n; ++i) {
                for (int j = 0; (j + len) <= n; ++j) {
                    dp[i][j][len] = false;
                    for (int xLen = 1, yLen = len - xLen; xLen + 1 <= len && !dp[i][j][len]; ++xLen, --yLen) {
                        if ((dp[i][j][xLen] && dp[i+xLen][j+xLen][yLen]) ||
                            (dp[i][j+yLen][xLen] && dp[i+xLen][j][yLen])) {
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }

    bool isScramble(string s1, string s2) {
        //return isScramble(s1, 0, s2, 0, s1.size());

        //map<tuple<uchar, uchar, uchar>, bool> cache;
        //return isScramble_memo(s1, 0, s2, 0, s1.size(), cache);

        return btmupDp(s1, s2);
    }
};
