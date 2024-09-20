class Solution {
public:
    string kmp(const string& s) {
        int n = s.size();
        if (n == 0) { return ""; }

        // lps[i]: the maximum value k such that s[0:k-1] == s[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        string t(s.rbegin(), s.rend());
        // dp[i]: the maximum value k such that s[0:k-1] == t[i-k+1:i]
        int dp = 0;
        for (int i = 0; i < n; ++i) {
            int j = dp;
            while (0 < j && t[i] != s[j]) {
                j = lps[j - 1];
            }
            dp = j + (t[i] == s[j] ? 1 : 0);
        }

        string ret = s.substr(dp);
        std::reverse(ret.begin(), ret.end());
        ret += s;

        return ret;
    }

    string manacher(const string& s) {
        string t = "#";
        for (char c : s) {
            t.append(1, c).append("#");
        }

        int n = t.size();
        int prefixPalindromeLen;
        vector<int> p(n); // p[i]: the longest extended radius of palindromic substring centered at i
        for (int i = 0, maxCtr = -1, maxRht = -1; i < n; ++i) {
            int r = 0;
            if (i < maxRht) {
                int j = maxCtr * 2 - i;
                r = std::min(p[j], maxRht - i);
            }
            while (0 <= (i - r - 1) && (i + r + 1) < n && t[i - r - 1] == t[i + r + 1]) {
                ++r;
            }
            p[i] = r;

            if (maxRht < (i + p[i])) {
                maxCtr = i;
                maxRht = i + p[i];
            }

            if (i == p[i]) {
                prefixPalindromeLen = p[i];
            }
        }

        string ret = s.substr(prefixPalindromeLen);
        std::reverse(ret.begin(), ret.end());
        ret = ret + s;

        return ret;
    }

    string shortestPalindrome(string s) {
        return kmp(s);
        //return manacher(s);
    }
};

/*
s:                  A A' B
Shortest palindrome can be found by adding B' in front of s => B' A A' B

t: reverse of s: B' A A'
*/
