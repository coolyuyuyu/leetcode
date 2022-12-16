class Solution {
public:
    long long M = 1e9 + 7;

    bool checkPrime(char c) {
        return c=='2' || c=='3' || c=='5' || c=='7';
    }

    // Time: O(n * numPart * n)
    int dp1(string s, int numParts, int minLength) {
        int n = s.size();
        s = "#" + s;
        vector<vector<long long>> dp(n+1, vector<long long>(numParts+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= numParts; ++j) {
                if (checkPrime(s[i])) {
                    continue;
                }

                for (int k = j; k <= i-minLength+1; ++k) {
                    if (checkPrime(s[k])) {
                        dp[i][j] = (dp[i][j] + dp[k-1][j-1]) % M;
                    }
                }
            }
        }

        return dp[n][numParts];
    }

    // Time: O(n * numPart)
    int dp2(string s, int numParts, int minLength) {
        int n = s.size();
        s = "#" + s;
        vector<vector<long long>> dp(n+1, vector<long long>(numParts+1, 0));
        dp[0][0] = 1;
        for (int j = 1; j <= numParts; ++j) {
            long long sum = 0;
            for (int i = minLength*j; i <= n; ++i) {
                if (!checkPrime(s[i-minLength]) && checkPrime(s[i-minLength+1])) {
                    sum = (sum + dp[i-minLength][j-1]) % M;
                }

                if (!checkPrime(s[i])) {
                    dp[i][j] = sum;
                }
            }
        }

        return dp[n][numParts];
    }

    int beautifulPartitions(string s, int numParts, int minLength) {
        //return dp1(s, numParts, minLength);
        return dp2(s, numParts, minLength);
    }
};

/*
dp[i][j]: number of beautiful j non-intersecting substrings partitions of s[0:i]

X X X X [X X X]
         k   i
for k = 0 to i-minLength+1
    dp[i][j] += dp[k-1][j-1]
*/
