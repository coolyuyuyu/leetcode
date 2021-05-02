class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> counts;
        for (const auto& domino : dominoes) {
            int a = domino[0], b = domino[1];
            if (b < a) {
                swap(a, b);
            }

            ++counts[{a, b}];
        }

        int numPairs = 0;
        for (const auto& p : counts) {
            if (0 < p.second) {
                numPairs += (p.second * (p.second - 1) / 2);
            }
        }

        return numPairs;
    }
};
