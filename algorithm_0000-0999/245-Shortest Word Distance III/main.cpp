class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int ret = INT_MAX;
        bool identical = (word1 == word2);
        for (int i = 0, i1 = 1e6, i2 = -1e6; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                if (identical) {
                    i2 = i1;
                }
                i1 = i;
            }
            else if (wordsDict[i] == word2) {
                i2 = i;
            }

            ret = std::min(ret, abs(i1 - i2));
        }

        return ret;
    }
};
