class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt[n * n + 1];
        for (int i = 1; i <= n * n; ++i) {
            cnt[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++cnt[grid[i][j]];
            }
        }

        vector<int> ret(2);
        for (int i = 1; i <= n * n; ++i) {
            if (cnt[i] == 2) {
                ret[0] = i;
            }
            else if (cnt[i] == 0) {
                ret[1] = i;
            }
        }

        return ret;
    }
};
