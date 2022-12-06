class Solution {
public:
    // Time: O(n), Space: O(n)
    int dp1(const string& s) {
        size_t n = s.size();
        vector<int> dp(n, 0); // dp[i]: number of decode ways for string s[0:i+1]
        dp[0] = (s[0] == '0' ? 0 : 1);
        for (size_t i = 1; i < n; ++i) {
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            if ((s[i - 1] == '2' && s[i] <= '6') || s[i - 1] == '1') {
                dp[i] += (2 <= i ? dp[i - 2] : 1);
            }
        }

        return dp.back();
    }

    // Time: O(n), Space: O(1)
    int dp2(const string& s) {
        size_t n = s.size();
        int x = (s[0] == '0' ? 0 : 1), y, z;
        for (size_t i = 1; i < n; ++i) {
            z = y, y = x, x = 0;

            if (s[i] != '0') {
                x += y;
            }
            if ((s[i - 1] == '2' && s[i] <= '6') || s[i - 1] == '1') {
                x += (2 <= i ? z : 1);
            }
        }

        return x;
    }

    int numDecodings(string s) {
        //return dp1(s);
        return dp2(s);
    }
};
