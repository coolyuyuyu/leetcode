class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t n = std::min(word1.size(), word2.size());

        string ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(word1[i]);
            ret.push_back(word2[i]);
        }
        ret.append(word1.begin() + n, word1.end());
        ret.append(word2.begin() + n, word2.end());

        return ret;
    }
};
