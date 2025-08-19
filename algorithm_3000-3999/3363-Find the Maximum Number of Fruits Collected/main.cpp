class Solution {
public:
    int f(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int rowCnt = fruits.size() - 1;

        vector<vector<int>> vals(rowCnt);
        int r;
        for (r = 0; r < (rowCnt/ 2); ++r) {
            int colCnt = r + 1;
            for (int c = n - 1; c >= n - colCnt; --c) {
                vals[r].push_back(fruits[r][c]);
            }
        }
        if (rowCnt & 1) {
            int colCnt = (r > 0 ? vals[r - 1].size() : 0) + 1;
            for (int c = n - 1; c >= n - colCnt; --c) {
                vals[r].push_back(fruits[r][c]);
            }
            ++r;
        }
        for (int colCnt = rowCnt / 2; r < rowCnt; ++r, --colCnt) {
            for (int c = n - 1; c >= n - colCnt; --c) {
                vals[r].push_back(fruits[r][c]);
            }
        }

        for (int r = 1; r < vals.size(); ++r) {
            for (int c = 0; c < vals[r].size(); ++c){
                int lt = c > 0 ? vals[r - 1][c - 1] : 0;
                int tp = c < vals[r - 1].size() ? vals[r - 1][c] : 0;
                int rt = c + 1 < vals[r - 1].size() ? vals[r - 1][c + 1] : 0;
                vals[r][c] += std::max({lt, tp, rt});
            }
        }

        return vals.back().back();
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += fruits[i][i];
        }

        ret += f(fruits);

        for (int r = 0; r < n; ++r) {
            for (int c = r + 1; c < n; ++c) {
                std::swap(fruits[r][c], fruits[c][r]);
            }
        }
        ret += f(fruits);

        return ret;
    }
};
