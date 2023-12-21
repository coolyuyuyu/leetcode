class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze.empty() ? 0 : maze[0].size();
        vector<tuple<char, int, int>> dirs = {{'l', 0, -1}, {'u', -1, 0}, {'r', 0, 1}, {'d', 1, 0}};

        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }

        priority_queue<tuple<int, string, int, int>, vector<tuple<int, string, int, int>>, std::greater<tuple<int, string, int, int>>> pq;
        pq.emplace(0, "", ball[0], ball[1]);
        while (!pq.empty()) {
            auto [d, i, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) { continue;}
            visited[r][c] = true;

            if (r == hole[0] && c == hole[1]) {
                return i;
            }

            for (const auto& [mark, dr, dc] : dirs) {
                int z = d;
                string t = i + mark;
                int x = r, y = c;
                while (
                    !(x == hole[0] && y == hole[1]) &&
                    0 <= x + dr &&
                    x + dr < m&&
                    0 <= y + dc &&
                    y + dc < n &&
                    maze[x + dr][y + dc] == 0) {
                    z += 1;
                    x += dr, y += dc;
                }
                if (visited[x][y]) { continue; }

                pq.emplace(z, t, x, y);
            }
        }

        return "impossible";
    }
};
