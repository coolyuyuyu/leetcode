class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze.empty() ? 0 : maze[0].size();
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq;
        pq.emplace(0, start[0], start[1]);
        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) { continue;}
            visited[r][c] = true;

            if (r == destination[0] && c == destination[1]) {
                return d;
            }

            for (const auto& [dr, dc] : dirs) {
                int z = d, x = r, y = c;
                while (
                    0 <= x + dr &&
                    x + dr < m&&
                    0 <= y + dc &&
                    y + dc < n &&
                    maze[x + dr][y + dc] == 0) {
                    z += 1;
                    x += dr, y += dc;
                }
                if (visited[x][y]) { continue; }

                pq.emplace(z, x, y);
            }
        }

        return -1;
    }
};
