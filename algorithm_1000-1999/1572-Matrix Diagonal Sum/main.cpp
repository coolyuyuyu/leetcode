class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        size_t n = mat.size();

        int sum = 0;
        for (size_t i = 0; i < n; ++i) {
            sum += mat[i][i];
            sum += mat[i][n - i - 1];
        }
        if ((n % 2) == 1) {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};
