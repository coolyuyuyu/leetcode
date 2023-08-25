class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        istringstream iss(text);
        int ret = 0;
        for (string word; std::getline(iss, word, ' ');) {
            bool can = true;
            for (char c : word) {
                if (broken[c - 'a']) {
                    can = false;
                    break;
                }
            }

            if (can) {
                ++ret;
            }
        }

        return ret;
    }
};
