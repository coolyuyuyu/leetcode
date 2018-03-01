class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        size_t minDistance = numeric_limits<size_t>::max();
        size_t index1 = 0, index2 = 0;
        bool found1 = false, found2 = false;
        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                found1 = true;
                index1 = i;
                if (found2) {
                    minDistance = min(minDistance, index1 - index2);
                }
            }
            else if (words[i] == word2) {
                found2 = true;
                index2 = i;
                if (found1) {
                    minDistance = min(minDistance, index2 - index1);
                }
            }

        }

        return minDistance;
    }
};