class Solution {
public:
    bool dfs(const string& s, size_t start, const vector<string>& words) {
        if (s.size() <= start) {
            return true;
        }

        size_t remainlen = s.size() - start;
        for (const string& word : words) {
            if (remainlen < word.size()) {
                break;
            }
            if (s.compare(start, word.size(), word) == 0 && dfs(s, start + word.size(), words)) {
                return true;
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        std::sort(wordDict.begin(), wordDict.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });
        return dfs(s, 0, wordDict);
    }
};
