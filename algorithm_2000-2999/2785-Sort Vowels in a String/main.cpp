class Solution {
public:
    string sortVowels(string s) {
        std::function<bool(char)> isVowel = [](char c) {
            switch (tolower(c)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
            }
        };

        string vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels += c;
            }
        }
        std::sort(vowels.begin(), vowels.end());

        string t = s;
        for (int i = 0, j = 0; i < t.size(); ++i) {
            if (isVowel(t[i])) {
                t[i] = vowels[j++];
            }
        }

        return t;
    }
};
