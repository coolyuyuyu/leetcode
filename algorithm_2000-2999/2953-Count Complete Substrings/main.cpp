class Solution {
public:
    bool check(vector<int>& freq, int k)
    {
        for (int x: freq)
        {
            if (x != k && x != 0)
                return false;
        }
        return true;
    }
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();

        std::function<int(int, int)> f = [&](int bgn, int end) {
            unordered_set<char> chars(word.begin() + bgn, word.begin() + end);
            int ret = 0;
            for (int len = k; len <= chars.size() * k; len += k) {
                int cnts[26];
                std::fill(cnts, cnts + 26, 0);
                for (int lft = bgn, rht = bgn; lft + len - 1 < end; ++lft) {
                    for (; rht < (lft + len); ++rht) {
                        ++cnts[word[rht] - 'a'];
                    }

                    ret += std::all_of(chars.begin(), chars.end(), [&](char c){ return cnts[c - 'a'] == 0 || cnts[c - 'a'] == k; }) ? 1 : 0;

                    --cnts[word[lft] - 'a'];
                }
            }

            return ret;
        };

        int ret = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            for (; j < n; ++j) {
                if (std::abs(word[j] - word[j - 1]) > 2) {
                    break;
                }
            }

            if (j - i >= k) {
                ret += f(i, j);
            }

            i = j;
        }

        return ret;
    }
};
