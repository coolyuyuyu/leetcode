class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        int idx = 1;
        for (string word; iss >> word; ++idx) {
            if (word.compare(0, searchWord.size(), searchWord) == 0) {
                return idx;
            }
        }

        return -1;
    }
};
