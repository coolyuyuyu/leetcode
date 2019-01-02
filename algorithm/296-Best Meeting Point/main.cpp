class Solution {
public:
    size_t minTotalDistances1D(const vector<size_t>& positions, size_t target) {
        size_t distance = 0;
        for (size_t pos : positions) {
            distance += (pos > target ? pos - target : target - pos);
        }
        return distance;
    }

    int minTotalDistance(vector<vector<int>>& grid) {
        vector<size_t> rows, cols;
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (grid[row][col] == 1) {
                    rows.emplace_back(row);
                    cols.emplace_back(col);
                }
            }
        }

        //sort(rows.begin(), rows.end()); row is already sorted.
        sort(cols.begin(), cols.end());

        return minTotalDistances1D(rows, rows[rows.size() / 2]) + minTotalDistances1D(cols, cols[cols.size() / 2]);
    }
};