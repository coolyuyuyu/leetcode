class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();

        std::function<int(int, int)> f = [&](int a, int b) {
            int ret = 0;
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    if ((r <= n / 2 && (r == c || r + c + 1 == n)) || (r > n / 2 && c == n / 2)) {
                        if (grid[r][c] != a) {
                            ++ret;
                        }
                    }
                    else {
                        if (grid[r][c] != b) {
                            ++ret;
                        }
                    }
                }
            }

            return ret;
        };

        int ret = INT_MAX;
        ret = std::min(ret, f(0, 1));
        ret = std::min(ret, f(0, 2));
        ret = std::min(ret, f(1, 0));
        ret = std::min(ret, f(1, 2));
        ret = std::min(ret, f(2, 0));
        ret = std::min(ret, f(2, 1));
        return ret;
    }
};
