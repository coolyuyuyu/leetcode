class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<unsigned, 26> weights;
        for (int i = 0; i < 26; ++i) {
            weights[order[i] - 'a'] = i;
        }

        auto comp = [&](const string& s1, const string& s2) {
            auto itr1 = s1.begin(), itr2 = s2.begin();
            for (; itr1 != s1.end(); ++itr1, ++itr2) {
                if (itr2 == s2.end() || weights[*itr2 - 'a'] < weights[*itr1 - 'a']) {
                    return false;
                }
                else if (weights[*itr1 - 'a'] < weights[*itr2 - 'a']) {
                    return true;
                }
            }

            return itr2 != s2.end();
        };

        return std::is_sorted(words.begin(), words.end(), comp);
    }
};
