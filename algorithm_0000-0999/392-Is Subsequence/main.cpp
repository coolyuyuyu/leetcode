class Solution {
public:
    bool dp(const string& s, const string& t) {
        if (s.empty()) {
            return true;
        }

        for (size_t i = 0, j = 0; i < s.size() && j < t.size();) {
            if (s[i] == t[j]) {
                if (s.size() <= ++i) {
                    return true;
                }
            }
            ++j;
        }

        return false;
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
        //return dp(s, t);
        return bsearch(s, t);
    }
};
