class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cnts;
        for (char c : p) {
            ++cnts[c];
        }
        int diffCharCnt = cnts.size();

        vector<int> ret;
        for (size_t i = 0; i < s.size(); ++i) {
            if (--cnts[s[i]] == 0) {
                --diffCharCnt;
            }

            if (p.size() <= (i + 1)) {
                if (diffCharCnt == 0) {
                    ret.push_back(i + 1 - p.size());
                }

                if (cnts[s[i + 1 - p.size()]]++ == 0) {
                    ++diffCharCnt;
                }
            }
        }

        return ret;
    }
};
