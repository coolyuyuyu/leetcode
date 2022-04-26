class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        auto checkPalindrome = [](const string word) -> bool {
            for (size_t i = 0, j = word.size(); i < j; ++i) {
                if (word[i] != word[--j]) {
                    return false;
                }
            }

            return true;
        };

        vector<string>::iterator itr = std::find_if(words.begin(), words.end(), checkPalindrome);
        return itr == words.end() ? "" : *itr;
    }
};
