class Solution {
public:
    int M = 1e9 + 7;

    int dp1(string binary) {
        int n = binary.size();
        binary = "#" + binary;

        // dp[i]: number of unique subsequences from s[1:i]
        // assume dp[i - 1] contains following unique subsequences:
        //     X X X X X
        //     X X X X
        //     X X c
            
        // dp[i]:
        //     1. dp[i - 1] with s[i] as c:
        //         X X X X X c
        //         X X X X c
        //         X X c c         <- possible repetitions
        //         => dp[i] += dp[i - 1]
        //     2. dp[i - 1] without s[i] as c:
        //         X X X X X
        //         X X X X         <- possible repetitions
        //         X X c
        //         => dp[i] += dp[i - 1]
        //     3. possible repetitions such that subsequence ending at last s[i] at index j
        //         => dp[i] -= dp[j - 1];

        vector<int> last(2, 0);
        vector<int> dp(n + 1);

        int i = 0;
        for (; i <= n; ++i) {
            if (binary[i] == '1') {
                dp[i] = 1;
                ++i;
                break;
            }
        }

        for (; i <= n; ++i) {
            int j = last[binary[i] - '0'];
            //dp[i] = dp[i - 1] * 2 - (0 < j ? dp[j - 1] : 0);
            dp[i] = ((dp[i - 1] * 2) % M - (0 < j ? dp[j - 1] : 0) + M) % M;

            last[binary[i] - '0'] = i;
        }

        return dp[n] + (binary.find('0') != string::npos ? 1 : 0);
    }

    int dp2(string binary) {
        // zero: number of unique good subsequences ending with '0'
        // one: number of unique good subsequences ending with '1'
        // ==
        // zero: number of unique good subsequences ending at s[i]
        // one: number of unique good subsequences ending at s[i]

        int zero = 0, one = 0;
        for (char c : binary) {
            if (c == '0') {
                zero = (zero + one) % M;
            }
            else {
                one = (zero + one + 1) % M;
            }
        }

        return (zero + one + (binary.find('0') != string::npos ? 1 : 0)) % M;
    }

    int numberOfUniqueGoodSubsequences(string binary) {
        //return dp1(binary);
        return dp2(binary);
    }
};
