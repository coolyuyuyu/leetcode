class Solution {
public:

    
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze.empty() ? 0 : maze[0].size();

        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        auto nextPos = [&](int r, int c, const pair<int, int>& dir) {
            while (0 <= r && r < m && 0 <= c && c < n && maze[r][c] == 0) {
                r += dir.first;
                c += dir.second;
            }
 
            return std::make_pair(r - dir.first, c - dir.second);
        };

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.emplace(start[0], start[1]);
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto [r1, c1] = q.front();
            q.pop();

            for (const auto& dir : dirs) {
                auto [r2, c2] = nextPos(r1, c1, dir);
                if (r2 == destination[0] && c2 == destination[1]) { return true; }
                if (visited[r2][c2]) { continue; }

                q.emplace(r2, c2);
                visited[r2][c2] = true;
            }
        }

        return false;
    }
};
