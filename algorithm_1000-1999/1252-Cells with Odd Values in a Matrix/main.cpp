class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rowCounts(m, 0), colCounts(n, 0);
        for (auto& index : indices) {
            ++rowCounts[index[0]];
            ++colCounts[index[1]];
        }

        int oddRowCounts = 0, oddColCounts = 0; {
            for (int colCount : colCounts) {
                if (colCount % 2 == 1) {
                    ++oddColCounts;
                }
            }
            for (int rowCount : rowCounts) {
                if (rowCount % 2 == 1) {
                    ++oddRowCounts;
                }
            }
        }

        return (n * oddRowCounts + m * oddColCounts - 2 * oddRowCounts * oddColCounts);
    }
};
