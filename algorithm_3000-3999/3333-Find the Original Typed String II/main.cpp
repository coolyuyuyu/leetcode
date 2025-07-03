class Solution {
public:
    int M = 1e9 + 7;
    int possibleStringCount(string word, int k) {
        vector<int> cnts;
        for (int i = 0, cnt = 0; i <= word.size(); ++i, ++cnt) {
            if (i == word.size() || (i > 0 && word[i - 1] != word[i])) {
                cnts.push_back(cnt);
                cnt = 0;
            }
        }

        int n = cnts.size();
        cnts.insert(cnts.begin(), 0);

        int total = 1;
        for (int i = 1; i <= n; ++i) {
            total = 1L * total * cnts[i] % M;
        }

        if (k <= n) {
            return total;
        }

        // dp[i][]:  the total number of length k original strings from first i character groups
        int dp[k];
        std::fill(dp, dp + k, 0);
        dp[0] = 1;

        for (int i = 1; i <= std::min(n, k); ++i) {
            int tmp[k];
            std::copy(dp, dp + k, tmp);
            std::fill(dp, dp + k, 0);

            for (int j = 0, sum = 0; j < k; ++j) {
                if (j > 0) { sum = (sum + tmp[j - 1]) % M; }
                if (j - cnts[i] - 1 >= 0) {sum = ((sum - tmp[j - cnts[i] - 1]) % M + M) % M; }
                dp[j] = sum;
            }
        }

        int invalid = 0;
        for (int j = 0; j < k; ++j) {
            invalid = (invalid + dp[j]) % M;
        }

        return ((total - invalid) % M + M) % M;
    }
};
