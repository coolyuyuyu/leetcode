class Solution {
public:
    vector<tuple<char, int, int>> dirs = {{'l', 0, -1}, {'u', -1, 0}, {'r', 0, 1}, {'d', 1, 0}};

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze.empty() ? 0 : maze[0].size();
        std::function<tuple<int, int, int>(int, int, int, int)> rollAtMost = [&](int r, int c, int dr, int dc) {
            int cost = 0;
            for (int x, y; r != hole[0] || c != hole[1]; r = x, c = y) {
                x = r + dr, y = c + dc;
                if (x < 0 || x >= m || y < 0 || y >= n) { break; }
                if (maze[x][y] == 1) { break; }
                ++cost;
            }
            return make_tuple(r, c, cost);
        };

        bool visited[m][n];
        std::fill(&visited[0][0], &visited[0][0] + m * n, false);

        priority_queue<tuple<int, string, int, int>, vector<tuple<int, string, int, int>>, std::greater<>> pq; // <dist, instructions, r, c>
        pq.emplace(0, "", ball[0], ball[1]);
        while (!pq.empty()) {
            auto [dist, instructions, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) { continue; }
            visited[r][c] = true;

            if (r == hole[0] && c == hole[1]) {
                return instructions;
            }

            for (const auto& [instruction, dr, dc] : dirs) {
                auto [x, y, cost] = rollAtMost(r, c, dr, dc);
                if (visited[x][y]) { continue; }
                pq.emplace(dist + cost, instructions + instruction, x, y);
            }
        }

        return "impossible";
    }
};
