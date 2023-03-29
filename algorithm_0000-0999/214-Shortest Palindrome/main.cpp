class Solution {
public:
    vector<size_t> computeLPS(const string& s) {
        size_t n = s.size();

        vector<size_t> dp(n);
        dp[0] = 0;
        for (size_t i = 1; i < n; ++i) {
            size_t j = dp[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = dp[j - 1];
            }
            dp[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return dp;
    }

    string kmp(const string& s) {
        if (s.empty()) {
            return "";
        }

        string t = s;
        std::reverse(t.begin(), t.end());

        size_t n = t.size();

        vector<size_t> lps = computeLPS(s);
        size_t dp = (s[0] == t[0] ? 1 : 0);
        for (size_t i = 1; i < n; ++i) {
            size_t j = dp;
            while (0 < j && s[j] != t[i]) {
                j = lps[j - 1];
            }
            dp = j + (s[j] == t[i] ? 1 : 0);
        }

        string ret = s.substr(dp);
        std::reverse(ret.begin(), ret.end());
        ret = ret + s;

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
