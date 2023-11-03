class Solution {
public:
    vector<size_t> computeLPS(const string& s) {
        // dp[i]: the longest length k such that dp[0:k-1] == dp[i-k+1:i]
        vector<size_t> dp(s.size());
        dp[0] = 0;
        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = dp[i - 1];
            while (0 < j && s[j] != s[i]) {
                j = dp[j - 1];
            }
            dp[i] = j + (s[j] == s[i] ? 1 : 0);
        }

        return dp;
    }

    int countSubstr(const string& s, const string& t) {
        if (s.size() < t.size()) {
            return 0;
        }

        int cnt = 0;

        vector<size_t> lps = computeLPS(t);

        // dp[i]: the longest length k such that t[0:k-1] == s[i-k+1:i]
        vector<size_t> dp(s.size());
        dp[0] = (s[0] == t[0] ? 1 : 0);
        if (dp[0] == 1 && t.size() == 1) {
            ++cnt;
        }
        for (size_t i = 1; i < s.size(); ++i) {
            size_t j = dp[i - 1];
            while (0 < j && (j == t.size() || t[j] != s[i])) {
                j = lps[j - 1];
            }
            dp[i] = j + (t[j] == s[i] ? 1 : 0);

            if (dp[i] == t.size()) {
                ++cnt;
            }
        }

        return cnt;
    }

    using LL = long long;
    LL M = 1e9 + 7;
    vector<LL> multiply(vector<LL> mat1, vector<LL> mat2) {
        // a1 b1       a2 b2
        // c1 d1       c2 d2
        LL a1 = mat1[0], b1 = mat1[1], c1 = mat1[2], d1 = mat1[3];
        LL a2 = mat2[0], b2 = mat2[1], c2 = mat2[2], d2 = mat2[3];
        LL a = ((a1 * a2) % M + (b1 * c2) % M) % M;
        LL b = ((a1 * b2) % M + (b1 * d2) % M) % M;
        LL c = ((c1 * a2) % M + (d1 * c2) % M) % M;
        LL d = ((c1 * b2) % M + (d1 * d2) % M) % M;
        return {a, b, c, d};
    }

    vector<LL> quickMul(vector<LL> mat, LL k) {
        if (k == 0) { return {1, 0, 0, 1}; }
        vector<LL> half = quickMul(mat, k / 2);
        if (k & 1) {
            return multiply(multiply(half, half), mat);
        }
        else {
            return multiply(half, half);
        }
    }

    int numberOfWays(string s, string t, long long k) {
        int n = s.size();

        // in one operation s => s'
        // => s' is a shift of s

        // 1. count how many shifts of s equal to t as p
        // => overall n differnt shifts
        // => s(0): shift s 0
        // => s(1): shift s 1
        string ss = s + s; ss.pop_back();
        int p = countSubstr(ss, t);

        // 2. count how many good/bad string after j operations.
        // bad string: not match t
        // good string: match t
        // f[j]: the number of bad string after j operations
        // g[j]: the number of good string after j operations
        // f[j] = (n - p - 1) * f[j - 1] + (n - p) * g[j - 1]
        // g[j] = (p)         * f[j - 1] + (p - 1) * g[j - 1]
        // => form a transform matrix from above equation
        // f[0], g[0] = 0, 1 (if s == t)
        //            = 1, 0 (if s != t)

        vector<LL> T = {n - p - 1, n - p, p, p - 1};
        vector<LL> Tk = quickMul(T, k);
        if (s == t) {
            return Tk[3];
        }
        else {
            return Tk[2];
        }
    }
};
