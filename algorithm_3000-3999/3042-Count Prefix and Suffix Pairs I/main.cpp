class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int ret = 0;
        for (int j = 0; j < n; ++j) {
            const string& wordJ = words[j];
            for (int i = 0; i < j; ++i) {
                const string& wordI = words[i];
                if (wordJ.compare(0, wordI.size(), wordI) == 0 &&
                    wordJ.compare(wordJ.size() - wordI.size(), wordI.size(), wordI) == 0) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
