class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLowers(26, -1), firstUppers(26, -1);
        for (int i = 0; i < word.size(); ++i) {
            if (islower(word[i])) {
                lastLowers[word[i] - 'a'] = i;
            }
        }
        for (int i = word.size(); 0 < i--;) {
            if (isupper(word[i])) {
                firstUppers[word[i] - 'A'] = i;
            }
        }

        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (lastLowers[i] == -1 || firstUppers[i] == -1) {
                continue;
            }
            if (lastLowers[i] < firstUppers[i]) {
                ++ret;
            }
        }
        return ret;
    }
};
