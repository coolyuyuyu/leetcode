class Solution {
public:
    // Time(m,n) = O(m*n), Space(m,n) = O(m*n)
    size_t findLonelyPixelV1(const vector<vector<char>>& picture) {
        size_t rowCnt = picture.size(), colCnt = picture.empty() ? 0 : picture.front().size();
        vector<int> dpRow(rowCnt, 0), dpCol(colCnt, 0);
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (picture[row][col] == 'B') {
                    ++dpRow[row];
                    ++dpCol[col];
                }
            }
        }

        size_t count = 0;
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (picture[row][col] == 'B' && dpRow[row] == 1 && dpCol[col] == 1) {
                    ++count;
                }
            }
        }

        return count;
    }
    
    size_t findLonelyPixel(const vector<vector<char>>& picture) {
        return findLonelyPixelV1(picture);
    }
};