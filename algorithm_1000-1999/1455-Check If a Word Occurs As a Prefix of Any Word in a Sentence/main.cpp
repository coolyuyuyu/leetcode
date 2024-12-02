class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        int idx = 1;
        for (istringstream iss(sentence); iss >> word; ++idx) {
            if (word.compare(0, searchWord.size(), searchWord) == 0) {
                return idx;
            }
        }

        return -1;
    }
};
