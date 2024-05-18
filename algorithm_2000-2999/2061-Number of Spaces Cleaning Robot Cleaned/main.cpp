class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int numberOfCleanRooms(vector<vector<int>>& room) {
        int m = room.size(), n = room.empty() ? 0 : room[0].size();

        int visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = 0;
            }
        }

        int r = 0, c = 0, dir = 0;
        int ret = 0;
        while (((visited[r][c] >> dir) & 1) == 0) {
            if (visited[r][c] == 0) {
                ++ret;
            }
            visited[r][c] |= (1 << dir);

            const auto& [dr, dc] = dirs[dir];
            int x = r + dr, y = c + dc;
            if (x < 0 || x >= m || y < 0 || y >= n || room[x][y] == 1) {
                dir = (dir + 1) % dirs.size();
            }
            else {
                r = x, c = y;
            }
        }

        return ret;
    }
};
