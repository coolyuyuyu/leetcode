class Solution {
public:
    string customSortString(string order, string s) {
        int weights[26];
        std::fill(weights, weights + 26, INT_MAX);
        for (int i = 0; i < order.size(); ++i) {
            weights[order[i] - 'a'] = i;
        }

        std::sort(s.begin(), s.end(), [&](char c1, char c2){ return weights[c1 - 'a'] < weights[c2 - 'a']; });
        return s;
    }
};
