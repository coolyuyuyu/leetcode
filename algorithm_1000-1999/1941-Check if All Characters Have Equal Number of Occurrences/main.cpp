class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        for (const auto& [_, cnt] : cnts) {
            if (cnt != cnts.begin()->second) {
                return false;
            }
        }

        return true;
    }
};
