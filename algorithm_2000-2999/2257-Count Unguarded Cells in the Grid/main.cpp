class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0: unguarded, 1: guarded, 2: guard or wall
        int cell[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                cell[r][c] = 0;
            }
        }

        for (const auto& wall : walls) {
            int r = wall[0], c = wall[1];
            cell[r][c] = 2;
        }
        for (const auto& guard : guards) {
            int r = guard[0], c = guard[1];
            cell[r][c] = 2;
        }

        for (const auto& guard : guards) {
            for (const auto& [dr, dc] : dirs) {
                for (int r = guard[0] + dr, c = guard[1] + dc; r >= 0 && r < m && c >= 0 && c < n && cell[r][c] != 2; r += dr, c += dc) {
                    cell[r][c] = 1;
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (cell[r][c] == 0) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
