class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lowers(26, false), uppers(26, false);
        for (char c : word) {
            if (std::islower(c)) {
                lowers[c - 'a'] = true;
            }
            else {
                uppers[c - 'A'] = true;
            }
        }

        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            if (lowers[i] && uppers[i]) {
                ++ret;
            }
        }
        return ret;
    }
};
