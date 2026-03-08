class Solution {
public:
    string trimTrailingVowels(string s) {
        std::function<bool(char)> isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        while (!s.empty() && isVowel(s.back())) {
            s.pop_back();
        }

        return s;
    }
};
