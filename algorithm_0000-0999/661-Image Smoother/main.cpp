class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        size_t rowCnt = img.size(), colCnt = img.empty() ? 0 : img.front().size();

        vector<vector<int>> ans(rowCnt, vector<int>(colCnt));
        for (size_t r = 0; r < rowCnt; ++r) {
            size_t rb = (0 < r) ? (r - 1) : r;
            size_t re = ((r + 1) < rowCnt) ? (r + 2) : (r + 1);
            for (size_t c = 0; c < colCnt; ++c) {
                size_t cb = (0 < c) ? (c - 1) : c;
                size_t ce = ((c + 1) < colCnt) ? (c + 2) : (c + 1);

                int sum = 0;
                for (size_t ri = rb; ri < re; ++ri) {
                    for (size_t ci = cb; ci < ce; ++ci) {
                        sum += img[ri][ci];
                    }
                }
                ans[r][c] = sum / (re - rb) / (ce - cb);
            }
        }
        return ans;
    }
};
