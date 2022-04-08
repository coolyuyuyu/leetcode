class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int minDist = std::numeric_limits<int>::max();
        for (int idx1 = -1, idx2 = -1, i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                idx1 = i;
                if (0 <= idx2) {
                    minDist = std::min(minDist, idx1 - idx2);
                }
            }
            else if (wordsDict[i] == word2) {
                idx2 = i;
                if (0 <= idx1) {
                    minDist = std::min(minDist, idx2 - idx1);
                }
            }
        }

        return minDist;
    }
};
