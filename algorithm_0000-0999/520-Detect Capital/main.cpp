class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) {
            return true;
        }

        if (isupper(word[0])) {
            int upper = word.size() > 1 ? isupper(word[1]) : false;
            for (size_t i = 2; i < word.size(); ++i) {
                if (upper != isupper(word[i])) {
                    return false;
                }
            }
        }
        else {
            for (size_t i = 1; i < word.size(); ++i) {
                if (isupper(word[i])) {
                    return false;
                }
            }
        }

        return true;
    }
};