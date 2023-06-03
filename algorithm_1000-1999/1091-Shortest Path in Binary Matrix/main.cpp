class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.emplace(0, 0);
        for (int len = 1; !q.empty(); ++len) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1 && c == n - 1) {
                    return len;
                }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || n <= x || y < 0 || n <= y || grid[x][y] == 1) {
                        continue;
                    }
                    grid[x][y] = 1;
                    q.emplace(x, y);
                }
            }
        }

        return -1;
    }
};
