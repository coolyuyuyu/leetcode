class Solution {
public:
    // Time: O(n), Space: O(n)
    int dp1(string s) {
        int n = s.size();

        s.insert(s.begin(), '9' + 1);

        // dp[i]: the number of ways to decode s[1:i]
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = ('1' <= s[1]) ? 1 : 0 ;
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;
            if ('1' <= s[i]) {
                dp[i] += dp[i - 1];
            }
            if ('1' == s[i - 1] || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

     // Time: O(n), Space: O(1)
    int dp2(string s) {
        int n = s.size();

        s.insert(s.begin(), '9' + 1);

        // dp[i]: the number of ways to decode s[1:i]
        int pre = 1;
        int cur = ('1' <= s[1]) ? 1 : 0 ;
        for (int i = 2; i <= n; ++i) {
            int tmp = pre;
            pre = cur;

           cur = 0;
            if ('1' <= s[i]) {
                cur += pre;
            }
            if ('1' == s[i - 1] || (s[i - 1] == '2' && s[i] <= '6')) {
                cur += tmp;
            }
        }

        return cur;
    }

    int numDecodings(string s) {
        //return dp1(s);
        return dp2(s);
    }
};
