class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms.empty() ? 0 : rooms[0].size();

        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (rooms[r][c] == 0) {
                    q.emplace(r, c);
                }
            }
        }

        for (int d = 1; !q.empty(); ++d) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (rooms[x][y] == -1) { continue; }
                    if (d < rooms[x][y]) {
                        rooms[x][y] = d;
                        q.emplace(x, y);
                    }
                }
            }
        }
    }
};
