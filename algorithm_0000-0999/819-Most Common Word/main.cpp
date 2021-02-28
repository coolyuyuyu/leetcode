class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedStrs; {
            for (const string& str : banned) {
                bannedStrs.insert(str);
            }
        }
        unordered_map<string, int> counts;

        size_t prev = 0;
        for (size_t i = 0; i < paragraph.size(); ++i) {
            if ( !isalpha(paragraph[i])) {
                if (prev < i) {
                    string word = paragraph.substr(prev, i - prev);
                    transform(word.begin(), word.end(), word.begin(), ::tolower);

                    if (bannedStrs.find(word) == bannedStrs.end()) {
                        counts[word]++;
                    }
                }
                prev = i + 1;
            }
        }
        if (prev < paragraph.size()) {
            string word = paragraph.substr(prev);
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (bannedStrs.find(word) == bannedStrs.end()) {
                counts[word]++;
            }
        }

        string str;
        int maxCount = 0;
        for (auto elem : counts) {
            if (maxCount < elem.second) {
                maxCount = elem.second;
                str = elem.first;
            }
        }

        return str;
    }
};