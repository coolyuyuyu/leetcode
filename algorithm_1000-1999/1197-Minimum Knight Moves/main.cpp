class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) { return 0; }

        // tranforms to Quadrant 1
        x = abs(x), y = abs(y);

        // directions making it further are excluded
        vector<pair<int, int>> dirs = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}/*, {1, 2}, {2, 1}*/, {2, -1}, {1, -2}};

        int minCoor = -2, maxCoor = 300;
        int OFFSET = 0 - minCoor;
        bool visited[maxCoor - minCoor + 1][maxCoor - minCoor + 1];
        for (int x = minCoor; x <= maxCoor; ++x) {
            for (int y = minCoor; y <= maxCoor; ++y) {
                visited[x + OFFSET][y + OFFSET] = false;
            }
        }
        visited[x + OFFSET][y + OFFSET];

        queue<pair<int, int>> q({{x, y}});
        for (int ret = 0; !q.empty(); ++ret) {
            for (int n = q.size(); 0 < n--;) {
                auto [x, y] = q.front();
                q.pop();

                for (const auto& [dx, dy] : dirs) {
                    int r = x + dx, c = y + dy;
                    if (r < minCoor || maxCoor < r || c < minCoor || maxCoor < c ) { continue; }
                    if (visited[r + OFFSET][c + OFFSET]) {continue;}
                    if (r == 0 && c == 0) { return ret + 1; };
                    visited[r + OFFSET][c + OFFSET] = true;
                    q.emplace(r, c);
                }
            }
        }

        return -1;
    }
};
