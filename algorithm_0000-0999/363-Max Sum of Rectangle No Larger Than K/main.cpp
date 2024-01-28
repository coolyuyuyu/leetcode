class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        int ret = INT_MIN;
        for (int r1 = 0; r1 < m; ++r1) {
            int colSum[n];
            std::fill(colSum, colSum + n, 0);
            for (int r2 = r1; r2 < m; ++r2) {
                int sum = 0;
                set<int> sums = {0};
                for (int c = 0; c < n; ++c) {
                    colSum[c] += matrix[r2][c];
                    sum += colSum[c];

                    auto itr = sums.lower_bound(sum - k);
                    if (itr != sums.end()) {
                        ret = std::max(ret, sum - *itr);
                    }

                    sums.insert(sum);
                }
            }
        }

        return ret;
    }
};
