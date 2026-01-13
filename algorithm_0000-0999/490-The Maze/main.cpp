class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze.empty() ? 0 : maze[0].size();
        std::function<pair<int, int>(int, int, int, int)> rollAtMost = [&](int r, int c, int dr, int dc) {
            for (int x, y; true; r = x, c = y) {
                x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { break; }
                if (maze[x][y] == 1) { break; }
            }
            return make_pair(r, c);
        };

        bool visited[m][n];
        std::fill(&visited[0][0], &visited[0][0] + m * n, false);

        queue<pair<int, int>> q;
        visited[start[0]][start[1]] = true;
        q.emplace(start[0], start[1]);
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [dr, dc] : dirs) {
                auto [x, y] = rollAtMost(r, c, dr, dc);
                if (visited[x][y]) { continue; }
                if (x == destination[0] && y == destination[1]) { return true; }
                visited[x][y] = true;
                q.emplace(x, y);
            }
        }

        return false;
    }
};
