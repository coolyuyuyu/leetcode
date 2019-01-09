class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        size_t rowCnt = A.size(), colCnt = A.empty() ? 0 : A.front().size();
        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                int cost = A[row - 1][col];
                if (0 < col) {
                    cost = min(cost, A[row - 1][col - 1]);
                }
                if (col + 1 < colCnt) {
                    cost = min(cost, A[row - 1][col + 1]);
                }
                A[row][col] += cost;
            }
        }

        return *min_element(A.back().begin(), A.back().end());
    }
};