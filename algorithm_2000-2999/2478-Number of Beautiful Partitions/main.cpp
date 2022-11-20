class Solution {
public:
    inline bool checkPrime(char c) {
        static array<bool, 10> a = {false, false, true, true, false, true, false, true, false, false};
        return a[c - '0'];
    };

    // TLE
    int btmup(const string& s, int k, int minLen) {
        size_t n = s.size();

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (size_t j = 0; j < n; ++j) {
            dp[1][j] = checkPrime(s[0]) && !checkPrime(s[j]) ? 1 : 0;
        }

        for (size_t i = 2; i <= k; ++i) {
            for (size_t end = (i * minLen) - 1; end < n; ++end) {
                if (checkPrime(s[end])) {
                    continue;
                }

                for (size_t bgn = (i - 1) * minLen; (bgn + minLen - 1) <= end; ++bgn) {
                    if (checkPrime(s[bgn]) && !checkPrime(s[bgn-1])) {
                        dp[i][end] = (dp[i][end] + dp[i - 1][bgn - 1]) % 1000000007;
                    }
                }
            }
        }

        return dp[k][n - 1];
    }

    // AC
    int topdn(const string& s, int minLen, int i, int j, vector<vector<int>>& cache) {
        if (0 <= cache[i][j]) {
            return cache[i][j];
        }

        int cnt = 0;
        if (!checkPrime(s[0])) {
            // first substring is not beautiful
        }
        else if (checkPrime(s[j])) {
            // last substring is not beautiful
        }
        else if (i == 1) {
            cnt = 1;
        }
        else {
            for (size_t bgn = (i - 1) * minLen; (bgn + minLen - 1) <= j; ++bgn) {
                if (checkPrime(s[bgn]) && !checkPrime(s[bgn-1])) {
                    cnt = (cnt + topdn(s, minLen, i - 1, bgn - 1, cache)) % 1000000007;
                }
            }
        }

        return cache[i][j] = cnt;
    }

    int beautifulPartitions(string s, int k, int minLength) {
        // dp[i][j]: i non-intersecting substrings using s[0:j];

        // return btmup(s, k, minLength);

        vector<vector<int>> cache(k + 1, vector<int>(s.size(), -1));
        return topdn(s, minLength, k, s.size() - 1, cache);
    }
};
