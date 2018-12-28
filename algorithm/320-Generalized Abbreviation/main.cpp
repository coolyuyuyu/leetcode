class Solution {
public:
    void generateAbbreviationsRecv(const string& word, vector<bool> used, size_t index, vector<string>& abbrs) {
        if (word.size() <= index) {
            string abbr;
            for (size_t index = 0, preIndex = 0; index <= used.size(); ++index) {
                if (index == used.size() || used[index]) {
                    if (preIndex < index) {
                        abbr += to_string(index - preIndex);
                    }

                    if (index < used.size()) {
                        abbr.push_back(word[index]);
                    }
                    preIndex = index + 1;
                }
            }
            abbrs.emplace_back(abbr);
            return;
        }

        used[index] = true;
        generateAbbreviationsRecv(word, used, index + 1, abbrs);
        used[index] = false;
        generateAbbreviationsRecv(word, used, index + 1, abbrs);
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> abbrs;
        vector<bool> used(word.size(), false);
        generateAbbreviationsRecv(word, used, 0, abbrs);
        return abbrs;
    }
};