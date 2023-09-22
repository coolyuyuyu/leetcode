class Solution {
public:
    bool linearScan(const string& s, const string& t) {
        if (s.empty()) {
            return true;
        }

        int i = 0, j = 0;
        for (int i = 0, j = 0, m = s.size(), n = t.size(); j < n; ++j) {
            if (s[i] == t[j]) {
                if (++i == m) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dynamicProgramming(string& s, string& t) {
        int m = s.size(), n = t.size();
        s = "#" + s, t = "#" + t;

        // dp[i][j]: whether s[1:i] is a subsequence of t[1:j]
        bool dp[m + 1][n + 1];
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = true;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }

    // Preferable when we have a large number of s for a single t
    bool bsearch(const string& s, const string& t) {
        vector<vector<size_t>> indexesArr(26);
        for (size_t i = 0; i < t.size(); ++i) {
            indexesArr[t[i] - 'a'].push_back(i);
        }

        vector<pair<vector<size_t>::const_iterator, vector<size_t>::const_iterator>> ranges(26);
        for (char c = 'a'; c <= 'z'; ++c) {
            ranges[c - 'a'] = {indexesArr[c - 'a'].begin(), indexesArr[c - 'a'].end()};
        }

        size_t preIndex;
        for (size_t i = 0; i < s.size(); ++i) {
            auto& range = ranges[s[i] - 'a'];
            if (i == 0) {
                if (range.first == range.second) {
                    return false;
                }
                preIndex = *(range.first);
                ++(range.first);
            }
            else {
                auto itr = std::upper_bound(range.first, range.second, preIndex);
                if (itr == range.second) {
                    return false;
                }
                preIndex = *itr;
                range.first = itr + 1;
            }
        }

        return true;
    }

    bool isSubsequence(string s, string t) {
        //return linearScan(s, t);
        return dynamicProgramming(s, t);
        //return bsearch(s, t);
    }
};