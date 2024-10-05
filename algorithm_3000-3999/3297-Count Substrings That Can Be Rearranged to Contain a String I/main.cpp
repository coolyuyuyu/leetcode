class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> cnts(26, 0);
        for (char c : word2) {
            ++cnts[c - 'a'];
        }
        int uniqueCnt = std::count_if(cnts.begin(), cnts.end(), [](int cnt) { return cnt > 0; });

        long long ret = 0;
        for (int lft = 0, rht = 0, n = word1.size(); lft < n; ++lft) {
            for (; rht < n && uniqueCnt > 0; ++rht) {
                if (--cnts[word1[rht] - 'a'] == 0) {
                    --uniqueCnt;
                }
            }

            if (uniqueCnt == 0) {
                ret += (n - 1) - (rht - 1) + 1;
            }

            if (++cnts[word1[lft] - 'a'] == 1) {
                ++uniqueCnt;
            }
        }

        return ret;
    }
};
