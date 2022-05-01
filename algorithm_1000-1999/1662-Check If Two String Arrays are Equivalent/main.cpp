class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        size_t i = 0, j = 0;
        for (size_t a = 0, b = 0; i < word1.size() && j < word2.size();) {
            while (i < word1.size() && word1[i].size() <= a) {
                ++i;
                a = 0;
            }
            while (j < word2.size() && word2[j].size() <= b) {
                ++j;
                b = 0;
            }

            if (i < word1.size() && j < word2.size() && word1[i][a] != word2[j][b]) {
                return false;
            }
            ++a, ++b;
        }

        return word1.size() <= i && word2.size() <= j;
    }
};
