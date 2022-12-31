/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int rowCnt = dimensions[0], colCnt = dimensions[1];

        int ret = INT_MAX;
        for (int r = 0, c = colCnt - 1; r < rowCnt && 0 <= c;) {
            if (binaryMatrix.get(r, c)) {
                ret = std::min(ret, c);
                --c;
            }
            else {
                ++r;
            }
        }

        return ret == INT_MAX ? -1 : ret;

    }
};
