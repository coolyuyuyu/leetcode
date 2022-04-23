class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        array<int, 26> weights;
        for (size_t i = 0; i < order.size(); ++i) {
            weights[order[i] - 'a'] = i;
        }

        auto comp = [&](const string& str1, const string str2) {
            for (size_t i = 0; i < str1.size() && i < str2.size(); ++i) {
                if (str1[i] != str2[i]) {
                    return weights[str1[i]- 'a'] < weights[str2[i] - 'a'];
                }
            }

            return str1.size() < str2.size();
        };
        return std::is_sorted(words.begin(), words.end(), comp);
    }
};
