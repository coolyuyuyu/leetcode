class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        int dists[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dists[i][j] = INT_MAX / 2;
            }
        }
        for (int i = 0; i < n; ++i) {
            dists[i][i] = 0;
        }
        for (int i = 0; i + 1 < n; ++i) {
            dists[i][i + 1] = 1;
            dists[i + 1][i] = 1;
        }
        dists[x - 1][y - 1] = 1;
        dists[y - 1][x - 1] = 1;

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dists[i][k] + dists[k][j] < dists[i][j]) {
                        dists[i][j] = dists[i][k] + dists[k][j];
                    }
                }
            }
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) { continue; }
            ++ret[dists[i][j] - 1];
                }
        }

        return ret;
    }
};
