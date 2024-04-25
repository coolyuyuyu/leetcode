class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = s.size(), n = part.size();

        // lps[i] the maximum value k such that part[0:k-1] == part[i-k+1:i]
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (0 < j && part[j] != part[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (part[j] == part[i] ? 1 : 0);
        }

        string ret;
        vector<int> dp; // dp[i]: the maximum value k such that s[i-k+1:i]==part[0:k-1]
        for (char c : s) {
            ret.push_back(c);

            int j = dp.empty() ? 0 : dp.back();
            while (0 < j && c != part[j]) {
                j = lps[j - 1];
            }
            j = j + (c == part[j] ? 1 : 0);
            dp.push_back(j);

            if (dp.back() == n) {
                for (int k = 0; k < n; ++k) {
                    ret.pop_back();
                    dp.pop_back();
                }
            }
        }

        return ret;
    }
};
