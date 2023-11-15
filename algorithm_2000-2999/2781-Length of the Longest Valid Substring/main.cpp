class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size();

        typedef unsigned long long ULL;
        ULL base = 26;

        unordered_set<ULL> hashs[11];
        for (const string& str: forbidden) {
            ULL hash = 0;
            for (char c : str) {
                hash = hash * base + c - 'a';
            }

            hashs[str.size()].insert(hash);
        }

        unordered_map<int, vector<int>> m;

        ULL power = 1;
        for (int len = 1; len <= 10; ++len, power *= base) {
            if (hashs[len].empty()) { continue; }

            ULL hash = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (len <= i) {
                    hash -= (word[i - len] - 'a') * power;
                }
                hash = hash * base + word[i] - 'a';

                if (len - 1 <= i && hashs[len].find(hash) != hashs[len].end()) {
                    m[i - len + 1].push_back(i);
                }
            }
        }

        int ret = 0, rhtBound = n;
        for (int i = n; 0 < i--;) {
            if (m.find(i) != m.end()) {
                for (int rht : m[i]) {
                    rhtBound = std::min(rhtBound, rht);
                }
            }

            ret = std::max(ret, rhtBound - i);
        }

        return ret;
    }
};
