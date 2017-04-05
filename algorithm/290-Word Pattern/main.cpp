class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_set<string> used;
        unordered_map<char, string> table;
        istringstream issStr(str);
        size_t i = 0;
        for (; i < pattern.size() && !issStr.eof(); ++i) {
            char p = pattern[i];
            string s;
            issStr >> s;
            pair<unordered_map<char, std::string>::const_iterator, bool> resultTable = table.emplace(p, s);
            pair<unordered_set<string>::const_iterator, bool> resultUsed = used.emplace(s);
            if (resultTable.second) {
                if (!resultUsed.second) {
                    return false;
                }
            }
            else {
                if (resultTable.first->second != s) {
                    return false;
                }
            }
        }

        return i == pattern.size() && issStr.eof();
    }
};