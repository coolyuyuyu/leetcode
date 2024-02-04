class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size();

        typedef unsigned long long ULL;
        ULL base = 26;

        unordered_set<ULL> hashs[11];
        for (const string& s : forbidden) {
            ULL hash = 0;
            for (char c : s) {
                hash = hash * base + (c - 'a');
            }
            hashs[s.size()].insert(hash);
        }

        unordered_map<int, vector<int>> intervals;

        ULL power = 1;
        for (int len = 1; len <= 10; ++len, power *= base) {
            ULL hash = 0;
            for (int i = 0; i < n; ++i) {
                if (i >= len) {
                    hash = hash - (word[i - len] - 'a') * power;
                }
                hash = hash * base + (word[i] - 'a');

                if (i >= len - 1 && hashs[len].find(hash) != hashs[len].end()) {
                    intervals[i - len + 1].push_back(i);
                }
            }
        }

        int ret = 0;
        for (int i = n, rhtBound = n; 0 < i--;) {
            if (intervals.find(i) != intervals.end()) {
                for (int rht : intervals[i]) {
                    rhtBound = std::min(rhtBound, rht);
                }
            }
            ret = std::max(ret, rhtBound - i);
        }

        return ret;
    }
};
