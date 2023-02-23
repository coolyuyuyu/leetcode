class Solution {
public:
    int M = 1e9 + 7;

    int dp1(string s) {
        // dp[i]: the number of distinct subsequences of s[0:i], empty is counted.
        // dp[i] = dp[i - 1] * 2 - dp[j - 1], where j is the last index of s[i]

        // assume dp[i - 1] contains following distinct subsequences
        //     X X X
        //     X c
        //     X

        // dp[i]:
        //     1. do with s[i] as c
        //         X X X c
        //         X c c
        //         X c
        //     2. do without s[i] as c
        //         X X X
        //         X c
        //         X X
        //     => dp[i] += dp[i - 1] * 2

        //     3. possible repetitions such that subsequence ending at the last s[i] as index j.
        //        to consider repitive subsequnce, they are constructed by all j - 1 characters plus s[j]
        //     => dp[i] -= dp[j - 1]

        s.insert(0, "#");
        vector<long long> dp(s.size(), 0);
        dp[0] = 1;

        vector<long long> indexes(26, 0);
        for (int i = 1; i < s.size(); ++i) {
            int j = indexes[s[i] - 'a'];
            dp[i] = ((dp[i - 1] * 2) % M - (0 < j ? dp[j - 1] : 0) + M) % M;

            indexes[s[i] - 'a'] = i;
        }

        return (dp.back() - 1 + M) % M;
    }

    long long sum (const vector<long long>& nums) {
        long long ret = 0;
        for (long long num : nums) {
            ret = (ret + num) % M;
        }

        return ret;
    };

    int dp2(const string&s) {
        // dp[c]: the number of distinct non-empty subsequences ending with character c.
        // ==
        // dp[i]: the number of distinct non-empty subsequences ending at s[i].

        vector<long long> dp(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            dp[c - 'a'] = sum(dp) + 1;
        }

        return sum(dp);
    }

    int distinctSubseqII(string s) {
        //return dp1(s);
        return dp2(s);
    }
};
