class Solution {
public:
    bool match(const string& word, const string& pattern) {
        if (word.size() != pattern.size()) {
            return false;
        }

        size_t n = word.size();
        map<char, char> m1;
        map<char, char> m2;
        for (size_t i = 0; i < n; ++i) {
            auto p1 = m1.emplace(word[i], pattern[i]);
            if (p1.second) { // success
                auto p2 = m2.emplace(pattern[i], word[i]);
                if (!p2.second) {
                    return false;
                }
            }
            else {
                if (p1.first->second != pattern[i]) {
                    return false;
                }
            }
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (const string& word : words) {
            if (match(word, pattern)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};