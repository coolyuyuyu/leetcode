class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();
        std::function<void(int, int)> sortDiag = [&](int r, int c) {
            priority_queue<int, vector<int>, std::greater<int>> pq;
            for (int i = r, j = c; i < m && j < n; ++i, ++j) {
                pq.push(mat[i][j]);
            }
            for (int i = r, j = c; i < m && j < n; ++i, ++j, pq.pop()) {
                mat[i][j] = pq.top();
            }
        };

        sortDiag(0, 0);
        for (int r = 1; r < m; ++r) {
            sortDiag(r, 0);
        }
        for (int c = 1; c < n; ++c) {
            sortDiag(0, c);
        }

        return mat;
    }
};
