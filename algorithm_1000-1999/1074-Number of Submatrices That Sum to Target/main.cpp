class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        // presum[r][c]: sum(matrix[0][c], matrix[1][c], ..., matrix[r][c])
        int presum[m][n];
        for (int c = 0; c < n; ++c) {
            presum[0][c] = matrix[0][c];
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                presum[r][c] = presum[r - 1][c] + matrix[r][c];
            }
        }

        int ret = 0;
        for (int r1 = 0; r1 < m; ++r1) {
            for (int r2 = r1; r2 < m; ++r2) {
                int sum = 0;
                unordered_map<int, int> sum2cnt = {{0, 1}};
                for (int c = 0; c < n; ++c) {
                    sum += presum[r2][c] - (r1 > 0 ? presum[r1 - 1][c] : 0);
                    ret += sum2cnt[sum - target];
                    ++sum2cnt[sum];
                }
            }
        }

        return ret;
    }
};
