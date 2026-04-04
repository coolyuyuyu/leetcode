class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        long long rowSums[m], colSums[n];
        std::fill(rowSums, rowSums + m, 0);
        std::fill(colSums, colSums + n, 0);
        long long total = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                rowSums[r] += grid[r][c];
                colSums[c] += grid[r][c];
                total += grid[r][c];
            }
        }

        long long topSum = 0, btmSum = total;
        for (int r = 0; r + 1 < m; ++r) {
            topSum += rowSums[r];
            btmSum -= rowSums[r];
            if (topSum == btmSum) {
                return true;
            }
        }

        long long lftSum = 0, rhtSum = total;
        for (int c = 0; c + 1 < n; ++c) {
            lftSum += colSums[c];
            rhtSum -= colSums[c];
            if (lftSum == rhtSum) {
                return true;
            }
        }

        return false;
    }
};
