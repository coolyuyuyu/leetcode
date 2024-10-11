class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        int n = heroes.size();
        int hIndexes[n];
        std::iota(hIndexes, hIndexes + n, 0);
        std::sort(hIndexes, hIndexes + n, [&](int idx1, int idx2) { return heroes[idx1] < heroes[idx2]; });

        int m = monsters.size();
        int mIndexes[m];
        std::iota(mIndexes, mIndexes + m, 0);
        std::sort(mIndexes, mIndexes + m, [&](int idx1, int idx2) { return monsters[idx1] < monsters[idx2]; });

        vector<long long> ret(n);
        long long sum = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            for (; j < m && heroes[hIndexes[i]] >= monsters[mIndexes[j]]; ++j) {
                sum += coins[mIndexes[j]];
            }
            ret[hIndexes[i]] = sum;
        }

        return ret;
    }
};
