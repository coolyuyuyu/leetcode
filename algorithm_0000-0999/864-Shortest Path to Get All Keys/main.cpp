class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        unordered_set<uint8_t> visited[m][n];
        queue<tuple<int, int, int>> q;

        int keyCnt = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '@') {
                    visited[r][c].insert(0);
                    q.emplace(r, c, 0);
                }
                else if (islower(grid[r][c])) {
                    ++keyCnt;
                }
            }
        }
        int finalState = (1 << keyCnt) - 1;

        for (int step = 0; !q.empty(); ++step) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c, s] = q.front();
                q.pop();

                if (s == finalState) {
                    return step;
                }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc, t = s;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; } // out of range
                    if (islower(grid[x][y])){ t |= 1 << (grid[x][y] - 'a'); } // pick key

                    if (grid[x][y] == '#') { continue; } // wall
                    if (isupper(grid[x][y]) && (s >> (grid[x][y] - 'A') & 1) == 0) { continue; } // lock without key
                    if (visited[x][y].insert(t).second == false) { continue; } // visited

                    q.emplace(x, y, t);
                }
            }
        }

        return -1;
    }
};
