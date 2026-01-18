class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze.empty() ? 0 : maze[0].size();
        std::function<tuple<int, int, int>(int, int, int, int)> rollAtMost = [&](int r, int c, int dr, int dc) {
            int cost = 0;
            for (int x, y; true; r = x, c = y) {
                x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { break; }
                if (maze[x][y] == 1) { break; }
                ++cost;
            }
            return make_tuple(r, c, cost);
        };

        bool visited[m][n];
        std::fill(&visited[0][0], &visited[0][0] + m * n, false);

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<>> pq; // <dist, r, c>
        pq.emplace(0, start[0], start[1]);
        while (!pq.empty()) {
            auto [dist, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) { continue; }
            visited[r][c] = true;

            if (r == destination[0] && c == destination[1]) {
                return dist;
            }

            for (const auto& [dr, dc] : dirs) {
                auto [x, y, cost] = rollAtMost(r, c, dr, dc);
                if (visited[x][y]) { continue; }
                pq.emplace(dist + cost, x, y);
            }
        }

        return -1;
    }
};
