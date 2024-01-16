class Solution {
public:
    // KMP
    // Time: O(m + n)
    vector<int> findIndexes(const string& haystack, const string& needle) {
        int m = haystack.size(), n = needle.size();
        if (m == 0 || m < n) { return {}; }

        // lps[i]: the longest length k such that such that needle[0:k-1] == needle[i-k+1:i];
        int lps[n];
        lps[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (0 < j && needle[j] != needle[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (needle[j] == needle[i] ? 1 : 0);
        }

        vector<int> ret;

        // dp[i]: the longest length k such that such that haystack[i-k+1:i] == needle[0:k-1];
        int dp[m];
        dp[0] = (haystack[0] == needle[0] ? 1 : 0);
        if (dp[0] == 1 && n == 1) {
            ret.push_back(0);
        }
        for (int i = 1; i < m; ++i) {
            int j = dp[i - 1];
            while (0 < j && haystack[i] != needle[j]) {
                j = lps[j - 1];
            }
            dp[i] = j + (haystack[i] == needle[j] ? 1 : 0);

            if (dp[i] == n) {
                ret.push_back(i - n + 1);
            }
        }

        return ret;
    };

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> indexes1 = findIndexes(s, a), indexes2 = findIndexes(s, b);
        int m = indexes1.size(), n = indexes2.size();

        vector<int> ret;
        for (int i1 = 0, i2 = 0; i1 < m; ++i1) {
            while (i2 < n && indexes2[i2] - indexes1[i1] <= k) {
                if (std::abs(indexes2[i2] - indexes1[i1]) <= k) {
                    break;
                }
                ++i2;
            }

            if (i2 < n && std::abs(indexes2[i2] - indexes1[i1]) <= k) {
                ret.push_back(indexes1[i1]);
            }
        }

        return ret;
    }
};