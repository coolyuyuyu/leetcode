class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size(), n = potions.size();

        int indexes[m];
        std::iota(indexes, indexes + m, 0);
        std::sort(indexes, indexes + m, [&](int i1, int i2){ return spells[i1] > spells[i2]; });

        std::sort(potions.begin(), potions.end());

        vector<int> ret(m);
        for (int i = 0, j = 0; i < m; ++i) {
            long long spell = spells[indexes[i]];
            while (j < n && spell * potions[j] < success) {
                ++j;
            }
            ret[indexes[i]] = n - j;
        }

        return ret;
    }
};
