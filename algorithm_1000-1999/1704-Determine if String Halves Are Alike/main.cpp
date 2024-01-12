class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();

        std::function<bool(char)> isvowel = [](char c) {
            switch (std::toupper(c)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
            }
        };

        int cnt = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (isvowel(s[i])) {
                ++cnt;
            }
        }
        for (int i = n / 2; i < n; ++i) {
            if (isvowel(s[i])) {
                --cnt;
            }
        }

        return cnt == 0;
    }
};
