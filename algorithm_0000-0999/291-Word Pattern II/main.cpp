class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        int m = pattern.size(), n = s.size();
        unordered_map<char, string> char2word;
        unordered_set<string> words;
        std::function<bool(int, int)> f = [&](int i, int j) {
            if (i >= m && j >= n) { return true; }
            else if (i >= m || j >= n) { return false; }
            else if (char2word.find(pattern[i]) != char2word.end()) {
                const string& word = char2word[pattern[i]];
                return s.compare(j, word.size(), word) == 0 && f(i + 1, j + word.size());
            }

            char c = pattern[i];
            string word;
            for (; j < n; ++j) {
                word += s[j];
                if (words.find(word) != words.end()) { continue; }
                char2word[c] = word;
                words.insert(word);

                if (f(i + 1, j + 1)) {
                    return true;
                }

                char2word.erase(c);
                words.erase(word);
            }

            return false;
        };

        return f(0, 0);
    }
};
