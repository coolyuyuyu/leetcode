class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> table;
        for (auto c : t) {
            pair<unordered_map<char, int>::iterator, bool> p = table.emplace(c, 1);
            if (!p.second) {
                ++p.first->second;
            }
        }

        for (auto c : s) {
            unordered_map<char, int>::iterator iter = table.find(c);
            if (iter != table.end()) {
                if (iter->second == 1) {
                    table.erase(iter);
                }
                else if (iter->second == 0) {
                    return false;
                }
                else {
                    --iter->second;
                }
            }
            else {
                return false;
            }
        }

        return table.empty();
    }
};