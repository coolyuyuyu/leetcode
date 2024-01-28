class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        int ret = 0;
        for (int r1 = 0; r1 < m; ++r1) {
            int colSum[n];
            std::fill(colSum, colSum + n, 0);
            for (int r2 = r1; r2 < m; ++r2) {
                int sum = 0;
                unordered_map<int, int> sum2cnt = {{0, 1}};
                for (int c = 0; c < n; ++c) {
                    colSum[c] += matrix[r2][c];
                    sum += colSum[c];

                    ret += sum2cnt[sum - target];

                    ++sum2cnt[sum];
                }
            }
        }

        return ret;
    }
};
