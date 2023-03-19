class Solution {
public:
    bool checkVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int vowelStrings(vector<string>& words, int left, int right) {
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            if (checkVowel(words[i].front()) && checkVowel(words[i].back())) {
                ++ret;
            }
        }

        return ret;
    }
};
