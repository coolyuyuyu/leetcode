class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> cnts1(26, 0), cnts2(26, 0);
        for (char c : word1) {
            ++cnts1[c - 'a'];
        }
        for (char c : word2) {
            ++cnts2[c - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (abs(cnts1[i] - cnts2[i]) > 3) {
                return false;
            }
        }

        return true;
    }
};
