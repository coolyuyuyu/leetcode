class Solution {
public:
    vector<int> byBruteForce(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        unordered_set<int> sums;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                sums.emplace(grid[r][c]);
                for (int k = std::min({r, c, m - 1 - r, n - 1 - c}); k >= 1; --k) {
                    int sum = 0;
                    int i = r - k, j = c;
                    for (int s = 0; s < k; ++s) {
                        sum += grid[i][j];
                        i += 1;
                        j += 1;
                    }
                    for (int s = 0; s < k; ++s) {
                        sum += grid[i][j];
                        i += 1;
                        j -= 1;
                    }
                    for (int s = 0; s < k; ++s) {
                        sum += grid[i][j];
                        i -= 1;
                        j -= 1;
                    }
                    for (int s = 0; s < k; ++s) {
                        sum += grid[i][j];
                        i -= 1;
                        j += 1;
                    }

                    sums.emplace(sum);
                }
            }
        }

        vector<int> ret(sums.begin(), sums.end());
        std::sort(ret.begin(), ret.end(), std::greater<int>());
        if (ret.size() > 3) {
            ret.erase(ret.begin() + 3, ret.end());
        }

        return ret;
    }

    vector<int> byPreSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        cout << m << ": " << n << endl;

        int presum1[m][n]; // '\'
        int presum2[m][n]; // '/'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                presum1[r][c] = ((r > 0 && c > 0) ? presum1[r - 1][c - 1] : 0) + grid[r][c];
                presum2[r][c] = ((r > 0 && c < n - 1) ? presum2[r - 1][c + 1] : 0) + grid[r][c];
            }
        }

        unordered_set<int> sums;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                sums.emplace(grid[r][c]);
                for (int k = std::min({r, c, m - 1 - r, n - 1 - c}); k >= 1; --k) {
                    int sum = 0;
                    int r1, c1, r2, c2;

                    r1 = r - k, c1 = c;
                    r2 = r, c2 = c + k;
                    sum += presum1[r2][c2] - ((r1 >= 1 && c1 >= 1) ? presum1[r1 - 1][c1 - 1] : 0);

                    r1 = r, c1 = c - k;
                    r2 = r + k, c2 = c;
                    sum += presum1[r2][c2] - ((r1 >= 1 && c1 >= 1) ? presum1[r1 - 1][c1 - 1] : 0);

                    r1 = r - k, c1 = c;
                    r2 = r, c2 = c - k;
                    sum += presum2[r2 - 1][c2 + 1] - presum2[r1][c1];

                    r1 = r, c1 = c + k;
                    r2 = r + k, c2 = c;
                    sum += presum2[r2 - 1][c2 + 1] - presum2[r1][c1];

                    sums.emplace(sum);
                }
            }
        }

        vector<int> ret(sums.begin(), sums.end());
        std::sort(ret.begin(), ret.end(), std::greater<int>());
        if (ret.size() > 3) {
            ret.erase(ret.begin() + 3, ret.end());
        }

        return ret;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        //return byBruteForce(grid);
        return byPreSum(grid);
    }
};
