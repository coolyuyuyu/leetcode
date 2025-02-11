class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = s.size(), n = part.size();

        // lps[i]: the maximum value k such that part[0:k-1] == part[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && part[j] != part[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (part[j] == part[i] ? 1 : 0);
        }

        string ret;
        vector<int> dp;
        for (int i = 0; i < m; ++i) {
            ret.push_back(s[i]);
            int j = dp.empty() ? 0 : dp.back() ;
            while ((j > 0 && s[i] != part[j]) || j == n) {
                j = lps[j - 1];
            }
            j += (s[i] == part[j] ? 1 : 0);
            dp.push_back(j);

            if (dp.back() == n) {
                dp.erase(dp.end() - n, dp.end());
                ret.erase(ret.end() - n, ret.end());
            }
        }

        return ret;
    }
};
