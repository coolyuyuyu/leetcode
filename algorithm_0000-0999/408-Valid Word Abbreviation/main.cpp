class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        size_t i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if ('a' <= abbr[j]) {
                if (word[i] != abbr[j]) {
                    return false;
                }
                ++i, ++j;
            }
            else {
                if (abbr[j] == '0') {
                    return false;
                }

                int count = 0;
                do {
                    count *= 10;
                    count += abbr[j] - '0';
                    ++j;
                } while (j < abbr.size() && abbr[j] <= '9');

                i += count;
                if (i > word.size()) {
                    return false;
                }
            }
        }

        return i == word.size() && j == abbr.size();
    }
};