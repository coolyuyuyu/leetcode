class Solution {
public:
    // Time: O(n^2)
    int dynamicProgramming(string s) {
        int n = s.size();

        s = "#" + s;
        const string& s1 = s;
        const string& s2 = s;

        // dp[i][j]: the longest length k such that s1[i-k+1:i] == s2[j-k+1:j]
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 0;
            }
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j && s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = std::max(ret, dp[i][j]);
                }
            }
        }

        return ret;
    }

    // Time: O(nlogn)
    int rollingHash(string s) {
        int n = s.size();

        long base = 26;
        long modulo = 1e9 + 7;
        std::function<bool(int)> checkRepeatingSubstringOfLen = [&](int len) {
            long powOfHiBit = 1;
            for (int i = 1; i < len; ++i) {
                powOfHiBit = powOfHiBit * base % modulo;
            }

            unordered_set<long> hashs;

            long hash = 0;
            for (int i = 0; i < n; ++i) {
                if (i >= len) {
                    hash = (hash - (s[i - len] - 'a') * powOfHiBit) % modulo;
                    hash = (hash + modulo) % modulo;
                }
                hash = hash * base % modulo;
                hash = (hash + s[i] - 'a') % modulo;

                if (i >= len - 1 && hashs.insert(hash).second == false) {
                    return true;
                }
            }

            return false;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkRepeatingSubstringOfLen(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return checkRepeatingSubstringOfLen(lo) ? lo : 0;
    }

    int longestRepeatingSubstring(string s) {
        //return dynamicProgramming(s);
        return rollingHash(s);
    }
};
