class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        size_t n = A.size();
        for (size_t row = 0; row < n; ++row) {
            for (size_t col = 0; col * 2 + 1 < n; ++col) {
                int tmp = A[row][col];
                A[row][col] = (A[row][n - col - 1] == 1 ? 0 : 1);
                A[row][n - col - 1] = (tmp == 1 ? 0 : 1);
            }

            if (n % 2 == 1) {
                A[row][n / 2] = (A[row][n / 2] == 1 ? 0 : 1);
            }
        }

        return A;
    }
};