class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> remainings;
        for (size_t row = 0; row < 101; ++row) {
            remainings.emplace_back(row + 1, 0.0);
        }

        remainings[0][0] = poured;
        for (size_t row = 0; row <= query_row; ++row) {
            for (size_t col = 0; col <= row; ++col) {
                double remaining = remainings[row][col];
                if (remaining > 1.0) {
                    double spiltDown = (remaining - 1) / 2;
                    remainings[row + 1][col] += spiltDown;
                    remainings[row + 1][col + 1] += spiltDown;
                    remainings[row][col] = 1.0;
                }
            }
        }

        return remainings[query_row][query_glass];
    }
};