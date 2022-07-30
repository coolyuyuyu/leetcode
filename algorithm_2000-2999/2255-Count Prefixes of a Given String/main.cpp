class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        auto checkPrefix = [&s](const string& word) -> bool {
            if (s.size() < word.size()) {
                return false;
            }
            return s.compare(0, word.size(), word) == 0;
        };
        return std::count_if(words.begin(), words.end(), checkPrefix);
    }
};