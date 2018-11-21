class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        size_t rowCnt = M.size();
        size_t colCnt = M.front().size();
        vector<vector<int>> image(rowCnt, vector<int>(colCnt));
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                int count = 0;
                int scale = 0;

                if (row > 0) {
                    if (col > 0) {
                        count += 1;
                        scale += M[row - 1][col - 1];
                    }

                    count += 1;
                    scale += M[row - 1][col];

                    if (col + 1 < colCnt) {
                        count += 1;
                        scale += M[row - 1][col + 1];
                    }
                }

                if (col > 0) {
                    count += 1;
                    scale += M[row][col - 1];
                }

                count += 1;
                scale += M[row][col];

                if (col + 1 < colCnt) {
                    count += 1;
                    scale += M[row][col + 1];
                }

                if (row + 1 < rowCnt) {
                    if (col > 0) {
                        count += 1;
                        scale += M[row + 1][col - 1];
                    }

                    count += 1;
                    scale += M[row + 1][col];

                    if (col + 1 < colCnt) {
                        count += 1;
                        scale += M[row + 1][col + 1];
                    }
                }

                image[row][col] = scale / count;
            }
        }

        return image;
    }
};
