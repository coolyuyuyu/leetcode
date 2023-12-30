class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnts[26];
        std::fill(cnts, cnts + 26, 0);

        for (const string& word : words) {
            for (char c : word) {
                ++cnts[c - 'a'];
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (cnts[i] % words.size() != 0) {
                return false;
            }
        }
        return true;
    }
};
