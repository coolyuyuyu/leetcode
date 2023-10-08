class Solution {
public:
    std::vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze.empty() ? 0 : maze[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        bool resolved[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                resolved[r][c] = false;
            }
        }

        pq.emplace(0, start[0], start[1]);
        while (!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();

            if (r == destination[0] && c == destination[1]) {
                return d;
            }

            if (resolved[r][c]) {
                continue;
            }
            resolved[r][c] = true;

            for (const auto& [dr, dc] : dirs) {
                int newD = d, newR = r, newC = c;
                while (
                    0 <= newR + dr &&
                    newR + dr < m &&
                    0 <= newC + dc &&
                    newC + dc < n &&
                    maze[newR + dr][newC + dc] == 0) {
                    ++newD;
                    newR += dr, newC += dc;
                }
                if (resolved[newR][newC]) {
                    continue;
                }

                pq.emplace(newD, newR, newC);
            }
        }

        return -1;
    }
};
