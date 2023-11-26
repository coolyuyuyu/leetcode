class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        int heights[n];
        std::fill(heights, heights + n, 0);
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    heights[j] += 1;
                }
                else {
                    heights[j] = 0;
                }
            }

            int tmp[n];
            std::copy(heights, heights + n, tmp);
            std::sort(tmp, tmp + n, std::greater<int>());
            for (int j = 0; j < n; ++j) {
                ret = std::max(ret, tmp[j] * (j + 1));
            }
        }

        return ret;
    }
};
