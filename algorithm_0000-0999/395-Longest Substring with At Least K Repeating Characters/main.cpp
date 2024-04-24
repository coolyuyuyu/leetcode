class Solution {
public:
    int byTwoPtrs(const string& s, int k) {
        int n = s.size();
        std::function<int(int)> longestSubstringWithMDiffChars = [&](int m) {
            vector<int> cnts(26, 0);
            int diffCnt = 0;
            int qualifiedCnt = 0;
            int ret = 0;
            for (int lft = 0, rht = 0; rht < n; ++lft) {
                for (; rht < n && (diffCnt < m || (diffCnt == m && cnts[s[rht] - 'a'] > 0)); ++rht) {
                    if (cnts[s[rht] - 'a']++ == 0) {
                        ++diffCnt;
                    }
                    if (cnts[s[rht] - 'a'] == k) {
                        ++qualifiedCnt;
                    }
                }

                if (diffCnt == m && qualifiedCnt == m) {
                    ret = std::max(ret, rht - lft);
                }

                if (cnts[s[lft] - 'a'] == k) {
                    --qualifiedCnt;
                }
                if (--cnts[s[lft] - 'a'] == 0) {
                    --diffCnt;
                }
            }

            return ret;
        };

        int ret = 0;
        for (int i = 1; i <= 26; ++i) {
            cout << i << endl;
            ret = std::max(ret, longestSubstringWithMDiffChars(i));
        }

        return ret;
    }

    int byRecursion(const string& s, int k) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }
        if (std::all_of(cnts.begin(), cnts.end(), [&](int cnt){ return cnt == 0 || cnt >= k; })) {
            return s.size();
        }

        int ret = 0;
        for (int i = 0; i < s.size();) {
            int j = i;
            for (; j < s.size(); ++j) {
                if (cnts[s[j] - 'a'] < k) {
                    break;
                }
            }
            if (i < j) {
                ret = std::max(ret, byRecursion(s.substr(i, j - i), k));
            }

            i = j + 1;
        }

        return ret;
    }

    int longestSubstring(string s, int k) {
        //return byTwoPtrs(s, k);
        return byRecursion(s, k);
    }
};
