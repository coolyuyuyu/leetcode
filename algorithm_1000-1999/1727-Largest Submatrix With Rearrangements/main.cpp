class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        int heights[n];
        std::fill(heights, heights + n, 0);

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                heights[c] = (matrix[r][c] == 1 ? (heights[c] + 1) : 0);
            }

            int tmp[n];
            std::copy(heights, heights + n, tmp);
            std::sort(tmp, tmp + n, std::greater<int>());
            for (int c = 0; c < n; ++c) {
                ret = std::max(ret, tmp[c] * (c + 1));
            }
        }

        return ret;
    }
};
