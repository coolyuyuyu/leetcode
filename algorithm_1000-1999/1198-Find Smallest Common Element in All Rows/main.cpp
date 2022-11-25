class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        size_t rowCnt = mat.size(), colCnt = mat.empty() ? 0 : mat.front().size();
        vector<size_t> indexes(rowCnt, 0);

        int ans = -1;
        for (size_t row = 0, cnt = 0; cnt < rowCnt; row = (row + 1) % rowCnt) {
            while (indexes[row] < colCnt && mat[row][indexes[row]] < ans) {
                ++indexes[row];
            }
            if (colCnt <= indexes[row]) {
                return -1;
            }

            if (mat[row][indexes[row]] == ans) {
                ++cnt;
            }
            else {
                cnt = 0;
                ans = mat[row][indexes[row]];
            }
        }

        return ans;
    }
};
