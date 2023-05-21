class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;
        auto collectSurrounding = [&](int r, int c) {
            for (stack<pair<int, int>> stk({{r,c}}); !stk.empty();) {
                auto [r, c] = stk.top();
                stk.pop();

                if (grid[r][c] == 0) {
                    q.emplace(r, c);
                    continue;
                }
                else if (grid[r][c] == 2) {
                    continue;
                }
                else {
                    grid[r][c] = 2; // mark 2 as visited
                }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || n <= x || y < 0 || n <= y) {
                        continue;
                    }
                    stk.emplace(x, y);
                }
            }
        };
        bool found = false;
        for (int r = 0; r < n && !found; ++r) {
            for (int c = 0; c < n && !found; ++c) {
                if (grid[r][c] == 1) {
                    collectSurrounding(r, c);
                    found = true;
                }
            }
        }
        
        for (int steps = 0; !q.empty(); ++steps) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();

                if (grid[r][c] == 1) {
                    return steps;
                }

                if (grid[r][c] == 2) {
                    continue;
                }
                grid[r][c] = 2; // mark 2 as visited

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || n <= x || y < 0 || n <= y) {
                        continue;
                    }
                    q.emplace(x, y);
                }
            }
        }

        return -1;;
    }
};
