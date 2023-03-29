class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();

        vector<int> p(n); // p[i]: the longest extended radius of palindromic substring centered at i
        for (int i = 0, maxCtr = -1, maxRht = -1; i < n; ++i) {
            int r = 0;
            if (i <= maxRht) {
                int j = maxCtr * 2 - i;
                r = std::min(p[j], maxRht - i);
            }
            while (0 <= (i - r  - 1) && (i + r + 1) < n && s[i - r - 1] == s[i + r + 1]) {
                ++r;
            }
            p[i] = r;

            if (maxRht < (i + p[i])) {
                maxCtr = i;
                maxRht = i + p[i];
            }
        }

        // X X X X X X X X X X
        //               i
        //       ------j------ 
        vector<int> lft(n); // lft[i]: the length of longest palindromic substring from s[0:i];
        lft[0] = 1;
        for (int i = 1, j = 0; i < n; ++i) {
            while (j < i && (j + p[j]) < i) {
                ++j;
            }
            lft[i] = std::max(lft[i - 1], (i - j) * 2 + 1);
        }

        vector<int> rht(n); // rht[i]: the length of longest palindromic substring from s[i:n-1]
        rht[n - 1] = 1;
        for (int i = n - 2, j = n - 1; 0 <= i; --i) {
            while (i < j && i < (j - p[j])) {
                --j;
            }
            rht[i] = std::max(rht[i + 1], (j - i) * 2 + 1);
        }

        long long ret = 0;
        for (int i = 0; i < (n - 1); ++i) {
            ret = std::max(ret, (long long)lft[i] * (long long)rht[i + 1]);
        }

        return ret;
    }
};
