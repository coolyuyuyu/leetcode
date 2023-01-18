class Solution {
public:
    int dp1(const string& s) {
        int n = s.size();

        // dp0[i]: minimum number of flips to make s[0:i] monotone increasing s0 and s0[i] = '0';
        // dp1[i]: minimum number of flips to make s[0:i] monotone increasing s1 and s1[i] = '1';
        vector<int> dp0(n); dp0[0] = (s[0] == '0' ? 0 : 1);
        vector<int> dp1(n); dp1[0] = (s[0] == '1' ? 0 : 1);
        int cnt1 = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                dp0[i] = dp0[i - 1];
                dp1[i] = std::min(dp0[i - 1], dp1[i - 1]) + 1;
            }
            else {
                dp0[i] = dp0[i - 1] + 1;
                dp1[i] = std::min(dp0[i - 1], dp1[i - 1]);
            }
        }

        return std::min(dp0[n - 1], dp1[n - 1]);
    }

    int dp2(const string& s) {
        int n = s.size();

        // dp[i]: minimum number of flips to make s[0:i] monotone increasing
        vector<int> dp(n); dp[0] = 0;
        int cnt1 = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                dp[i] = std::min(cnt1, dp[i - 1] + 1);
            }
            else {
                ++cnt1;
                dp[i] = dp[i - 1];
            }
        }

        return dp[n - 1];
    }

    int dp3(const string& s) {
        int n = s.size();

        int ans = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ans = std::min(cnt1, ans + 1);
            }
            else {
                ++cnt1;
            }
        }

        return ans;
    }

    int two_window(const string& s) {
        // assume s is break into 2 part.
        // prefix: all 0
        // suffix: all 1;

        int n = s.size();
        int cnt0 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++cnt0;
            }
        }

        int ans = cnt0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                --cnt0;
                ans = std::min(ans, cnt0);
            }
            else {
                ++cnt0;
            }
        }
        return ans;
    }

    int minFlipsMonoIncr(string s) {
        // return dp1(s);
        // return dp2(s);
        // return dp3(s);
        return two_window(s);
    }
};
