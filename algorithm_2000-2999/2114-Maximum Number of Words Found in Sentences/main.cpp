class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxNumWords = 0;
        for (const string& sentence : sentences) {
            int numWords = std::count(sentence.begin(), sentence.end(), ' ') + 1;
            if (maxNumWords < numWords) {
                maxNumWords = numWords;
            }
        }

        return maxNumWords;
    }
};
