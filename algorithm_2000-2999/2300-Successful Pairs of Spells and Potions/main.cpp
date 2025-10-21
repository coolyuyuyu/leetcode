class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int idx1, int idx2){ return spells[idx1] > spells[idx2]; });

        std::sort(potions.begin(), potions.end());

        vector<int> ret(n);
        for (int i = 0, j = 0; i < n; ++i) {
            int idx = indexes[i], spell = spells[idx];
            while (j < m && 1L * spell * potions[j] < success) {
                ++j;
            }
            ret[idx] = m - j;
        }

        return ret;
    }
};
