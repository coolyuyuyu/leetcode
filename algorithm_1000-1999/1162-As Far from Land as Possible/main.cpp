class Solution {
public:
    int bfs( vector<vector<int>>& grid) {
        size_t n = grid.size();

        queue<pair<int, int>> lands;
        for (size_t r = 0; r < n; ++r) {
            for (size_t c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    lands.emplace(r, c);
                }
            }
        }

        vector<array<int, 2>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        int dist = -1;
        while (!lands.empty()) {
            for (int i = lands.size(); 0 < i--;) {
                auto [r, c] = lands.front();
                lands.pop();

                for (int j = 0; j < dirs.size(); ++j) {
                    int newR = r + dirs[j][0];
                    int newC = c + dirs[j][1];
                    if (newR < 0 || newC < 0 || n <= newR || n <= newC) {
                        continue;
                    }
                    if (grid[newR][newC] == 1) {
                        continue;
                    }

                    grid[newR][newC] = 1;
                    lands.emplace(newR, newC);
                }
            }
            dist++;
        }

        return (dist == 0 ? -1 : dist);
    }


    int dp(const vector<vector<int>>& grid) {
        size_t n = grid.size();

        int DIST_MAX = n + n - 1;
        vector<vector<int>> dp(n, vector<int>(n, DIST_MAX));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dp[r][c] = 0;
                }
                else {
                    dp[r][c] = std::min({
                        dp[r][c],
                        0 < r ? (dp[r - 1][c] + 1) : DIST_MAX,
                        0 < c ? (dp[r][c - 1] + 1) : DIST_MAX,
                    });
                }
            }
        }

        int dist = 0;
        for (int r = n; 0 < r--;) {
            for (int c = n; 0 < c--;) {
                dp[r][c] = std::min({
                        dp[r][c],
                        (r + 1) < n ? (dp[r + 1][c] + 1) : DIST_MAX,
                        (c + 1) < n ? (dp[r][c + 1] + 1) : DIST_MAX,
                });

                dist = std::max(dist, dp[r][c]);
            } 
        }

        return (dist == DIST_MAX || dist == 0) ? -1 : dist;
    }

    int maxDistance(vector<vector<int>>& grid) {
        //return bfs(grid);
        return dp(grid);
    }
};
