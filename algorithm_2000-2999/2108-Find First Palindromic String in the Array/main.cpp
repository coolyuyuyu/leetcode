class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        std::function<bool(const string&)> checkPalindrome = [](const string& s) {
            for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
                if (s[i] != s[j]) {
                    return false;
                }
            }
            return true;
        };

        auto itr = std::find_if(words.begin(), words.end(), checkPalindrome);
        return itr == words.end() ? "" : *itr;
    }
};
