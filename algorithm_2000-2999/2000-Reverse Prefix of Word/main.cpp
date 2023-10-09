class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto itr = std::find(word.begin(), word.end(), ch);
        if (itr != word.end()) {
            std::reverse(word.begin(), itr + 1);
        }

        return word;
    }
};
