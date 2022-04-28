class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        size_t remaining = s.size();
        for (const string& word : words) {
            if (remaining < word.size()) {
                return false;
            }

            remaining -= word.size();
            if (remaining == 0) {
                break;
            }
        }
        if (0 < remaining) {
            return false;
        }

        for (size_t i = 0, j = 0; i < s.size(); i += words[j].size(), ++j) {
            if (s.compare(i, words[j].size(), words[j]) != 0) {
                return false;
            }
        }

        return true;
    }
};
