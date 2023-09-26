class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int ret = INT_MAX;
        std::function<void(int, int)> dfs = [&](int pos, int move) {
            if (move >= ret) { return; }
            if (pos >= 9) {
                ret = std::min(ret, move);
                return;
            }

            int r = pos / 3, c = pos % 3;
            if (grid[r][c] == 0) {
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (grid[x][y] > 1) {
                            --grid[x][y];
                            ++grid[r][c];

                            dfs(pos + 1, move + abs(x - r) + abs(y - c));
                            --grid[r][c];
                            ++grid[x][y];
                        }
                    }
                }
            }
            else if (grid[r][c] >= 1) {
                dfs(pos + 1, move);
            }
        };
        dfs(0, 0);

        return ret;
    }
};
