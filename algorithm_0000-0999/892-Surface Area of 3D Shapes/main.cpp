class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            const vector<int>& row = grid[i];
            if (i + 1 < grid.size()) {
                const vector<int>& nxtRow = grid[i + 1];
                for (size_t j = 0; j < row.size(); ++j) {
                    if (row[j] <= 0) {
                        continue;
                    }

                    area += (row[j] * 4 + 2);
                    if (j + 1 < row.size()) {
                        area -= (min(row[j], row[j + 1]) * 2);
                    }
                    area -= (min(row[j], nxtRow[j]) * 2);
                }
            }
            else {
                for (size_t j = 0; j < row.size(); ++j) {
                    if (row[j] <= 0) {
                        continue;
                    }

                    area += (row[j] * 4 + 2);
                    if (j + 1 < row.size()) {
                        area -= (min(row[j], row[j + 1]) * 2);
                    }
                }
            }
        }

        return area;
    }
};