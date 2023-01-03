class Solution {
public:
    bool detectCapitalUse(string word) {
        if (islower(word[0])) {
            return std::none_of(word.begin() + 1, word.end(), [](char c){ return isupper(c); });
        }
        else {
            bool allUpper = true, allLower = true;
            for (size_t i = 1; i < word.size(); ++i) {
                if (isupper(word[i])) {
                    allLower = false;
                }
                else {
                    allUpper = false;
                }
            }
            return allUpper || allLower;
        }
    }
};
