class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (matrix[i][j]) {
                    ++ret[i], ++ret[j];
                }
            }
        }

        return ret;
    }
};
