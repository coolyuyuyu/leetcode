class Solution {
public:
    // Time: O(n^2)
    int byDP(string s) {
        int n = s.size();
        s = "#" + s;

        const string& s1 = s;
        const string& s2 = s;

        // dp[i][j]: the length k longest common substring from s1[1:i] and s2[1:j] such that s1[i-k+1:i] == s2[j-k+1:j]
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

    int byRollingHash(string s) {
        int n = s.size();

        using ULL = unsigned long long;
        std::function<bool(int)> checkRepeatingSubstring = [&](int len) {
            ULL base = 26, power = 1;
            for (int i = 1; i < len; ++i) {
                power *= base;
            }

            ULL hash = 0;
            unordered_set<ULL> hashs;
            for (int i = 0; i < n; ++i) {
                if (i >= len) {
                    hash -= (s[i - len] - 'a') * power;
                }
                hash = hash * base + (s[i] - 'a');
                if (i + 1 >= len) {
                    if (hashs.insert(hash).second == false) {
                        return true;
                    }
                }
            }

            return false;
        };

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkRepeatingSubstring(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }

    int longestRepeatingSubstring(string s) {
        //return byDP(s);
        return byRollingHash(s);
    }
};
