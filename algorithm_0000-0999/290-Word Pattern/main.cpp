class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> strMap;
        unordered_set<string> strTbl;

        size_t i = 0, j = 0;
        for (string token; i < pattern.size() && j <= s.size(); ++j) {
            if (j == s.size() || s[j] == ' ') {
                if (strMap[pattern[i]].empty()) {
                    strMap[pattern[i]] = token;
                    if (strTbl.insert(token).second == false) {
                        return false;
                    }
                }
                else if (strMap[pattern[i]] != token) {
                    return false;
                }

                ++i;
                token.clear();
            }
            else {
                token += s[j];
            }
        }



        return pattern.size() <= i  && s.size() <= j;
    }
};
