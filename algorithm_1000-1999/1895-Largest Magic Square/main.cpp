class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        std::function<bool(int, int, int)> checkRec = [&](int srcR, int srcC, int s) {
            int sum = 0;
            for (int r = 0; r < s; ++r) {
                sum += grid[srcR + r][srcC];
            }

            // checkH
            for (int r = 0; r < s; ++r) {
                int tmp = 0;
                for (int c = 0; c < s; ++c) {
                    tmp += grid[srcR + r][srcC + c];
                }
                if (tmp != sum) { return false; }
            }

            // checkH
            for (int c = 0; c < s; ++c) {
                int tmp = 0;
                for (int r = 0; r < s; ++r) {
                    tmp += grid[srcR + r][srcC + c];
                }
                if (tmp != sum) { return false; }
            }

            // checkD
            int tmp1 = 0, tmp2 = 0;
            for (int d = 0; d < s; ++d) {
                tmp1 += grid[srcR + d][srcC + d];
                tmp2 += grid[srcR + d][srcC + s - 1 - d];
            }
            if (tmp1 != sum) { return false; }
            if (tmp2 != sum) { return false; }

            return true;
        };

        std::function<bool(int)> checkSide = [&](int s) {
            for (int r = 0; r + s <= m; ++r) {
                for (int c = 0; c + s <= n; ++c) {
                    if (checkRec(r, c, s)) {
                        return true;
                    }
                }
            }

            return false;
        };

        int ret = 0;
        for (int s = 1; s <= std::min(m, n); ++s) {
            if (checkSide(s)) {
                ret = s;
            }
        }

        return ret;
    }
};
