class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        long long rowSums[m], colSums[n];
        std::fill(rowSums, rowSums + m, 0);
        std::fill(colSums, colSums + n, 0);
        long long total = 0;

        unordered_map<long long, int> val2minRow, val2maxRow, val2minCol, val2maxCol;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                rowSums[r] += grid[r][c];
                colSums[c] += grid[r][c];
                total += grid[r][c];
                if (val2minRow.find(grid[r][c]) == val2minRow.end()) {
                    val2minRow[grid[r][c]] = r;
                    val2maxRow[grid[r][c]] = r;
                    val2minCol[grid[r][c]] = c;
                    val2maxCol[grid[r][c]] = c;
                }
                else {
                    val2minRow[grid[r][c]] = std::min(val2minRow[grid[r][c]], r);
                    val2maxRow[grid[r][c]] = std::max(val2maxRow[grid[r][c]], r);
                    val2minCol[grid[r][c]] = std::min(val2minCol[grid[r][c]], c);
                    val2maxCol[grid[r][c]] = std::max(val2maxCol[grid[r][c]], c);
                }
            }
        }

        long long topSum = 0, btmSum = total;
        for (int r = 0; r + 1 < m; ++r) {
            topSum += rowSums[r];
            btmSum -= rowSums[r];
            if (topSum == btmSum) {
                return true;
            }

            long long diff = std::abs(topSum - btmSum);
            if (val2minRow.find(diff) != val2minRow.end()) {
                if (topSum > btmSum) {
                    if (r == 0 || n == 1) {
                        if (grid[0][0] == diff || grid[0][n - 1] == diff || grid[r][0] == diff) {
                            return true;
                        }
                    }
                    else if (val2minRow[diff] <= r) {
                        return true;
                    }
                }
                else {
                    if (r == m - 2 || n == 1) {
                        if (grid[r + 1][0] == diff || grid[r + 1][n - 1] == diff || grid[m - 1][0] == diff) {
                            return true;
                        }
                    }
                    else if (val2maxRow[diff] > r) {
                        return true;
                    }
                }
            }
        }

        long long lftSum = 0, rhtSum = total;
        for (int c = 0; c + 1 < n; ++c) {
            lftSum += colSums[c];
            rhtSum -= colSums[c];
            if (lftSum == rhtSum) {
                return true;
            }

            long long diff = std::abs(lftSum - rhtSum);
            if (val2minRow.find(diff) != val2minRow.end()) {
                if (lftSum > rhtSum) {
                    if (c == 0 || m == 1) {
                        if (grid[0][0] == diff || grid[m - 1][0] == diff || grid[0][c] == diff) {
                            return true;
                        }
                    }
                    else if (val2minCol[diff] <= c) {
                        return true;
                    }
                }
                else {
                    if (c == n - 2 || m == 1) {
                        if (grid[0][c + 1] == diff || grid[m - 1][c + 1] == diff || grid[m - 1][n - 1] == diff) {
                            cout << "" << endl;
                            return true;
                        }
                    }
                    else if (val2maxCol[diff] > c) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
