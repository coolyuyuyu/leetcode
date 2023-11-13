class Solution {
public:
    string sortVowels(string s) {
        std::function<bool(char)> isvowel = [](char c) {
            c = tolower(c);
            switch (c) {
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

        vector<char> vowels;
        for (char c : s) {
            if (isvowel(c)) {
                vowels.push_back(c);
            }
        }
        std::sort(vowels.begin(), vowels.end());

        int i = 0;
        for (char& c : s) {
            if (isvowel(c)) {
                c = vowels[i++];
            }
        }

        return s;
    }
};
