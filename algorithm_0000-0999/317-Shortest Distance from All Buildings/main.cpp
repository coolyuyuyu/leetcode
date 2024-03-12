class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    // BFS from empty land to all houses
    int f1(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int numHouses = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ++numHouses;
                }
            }
        }

        std::function<int(int, int)> bfs = [&](int r, int c) {
            assert(grid[r][c] == 0);

            int numReachedHouses = 0;
            int ret = 0;

            bool visited[m][n];
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    visited[r][c] = false;
                }
            }

            queue<pair<int, int>> q({{r, c}});
            visited[r][c] = true;
            for (int d = 0; !q.empty() && numReachedHouses < numHouses; ++d) {
                for (int i = q.size(); 0 < i--;) {
                    auto [r, c] = q.front();
                    q.pop();

                    if (grid[r][c] == 1) {
                        numReachedHouses += 1;
                        ret += d;
                        continue;
                    }

                    for (const auto& [dr, dc] : dirs) {
                        int x = r + dr, y = c + dc;
                        if (x < 0 || m <= x || y < 0 || n <= y) {
                            continue;
                        }
                        if (grid[x][y] == 2) {
                            continue;
                        }
                        if (visited[x][y]) {
                            continue;
                        }
                        visited[x][y] = true;
                        q.emplace(x, y);
                    }
                }
            }

            if (numReachedHouses < numHouses) {
                for (int r = 0; r < m; ++r) {
                    for (int c = 0; c < n; ++c) {
                        if (visited[r][c] && grid[r][c] == 0) {
                            grid[r][c] = 2;
                        }
                    }
                }
                return INT_MAX;
            }
            else {
                return ret;
            }
        };

        int ret = INT_MAX;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    ret = std::min(ret, bfs(r, c));
                }
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }

    // BFS from houses to empty land
    int f2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int houseReached[m][n];
        int distance[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                houseReached[r][c] = 0;
                distance[r][c] = 0;
            }
        }

        std::function<void(int, int)> bfs = [&](int r, int c) {
            assert(grid[r][c] == 1);

            bool visited[m][n];
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    visited[r][c] = false;
                }
            }

            queue<pair<int, int>> q({{r, c}});
            visited[r][c] = true;
            for (int d = 0; !q.empty(); ++d) {
                for (int i = q.size(); 0 < i--;) {
                    auto [r, c] = q.front();
                    q.pop();

                    houseReached[r][c] += 1;
                    distance[r][c] += d;

                    for (const auto& [dr, dc] : dirs) {
                        int x = r + dr, y = c + dc;
                        if (x < 0 || m <= x || y < 0 || n <= y) {
                            continue;
                        }
                        if (grid[x][y] != 0) {
                            continue;
                        }
                        if (visited[x][y]) {
                            continue;
                        }
                        visited[x][y] = true;
                        q.emplace(x, y);
                    }
                }
            }
        };

        int numHouses = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ++numHouses;
                    bfs(r, c);
                }
            }
        }

        int ret = INT_MAX;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0 && houseReached[r][c] == numHouses) {
                    ret = std::min(ret, distance[r][c]);
                }
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }

    // BFS from houses to empty land (optimized)
    int f3(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int distance[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                distance[r][c] = 0;
            }
        }

        int ret = INT_MAX;
        std::function<void(int, int, int)> bfs = [&](int r, int c, int empty) {
            assert(grid[r][c] == 1);

            ret = INT_MAX;

            queue<pair<int, int>> q({{r, c}});
            for (int d = 0; !q.empty(); ++d) {
                for (int i = q.size(); 0 < i--;) {
                    auto [r, c] = q.front();
                    q.pop();

                    if (grid[r][c] == empty - 1) {
                        distance[r][c] += d;
                        ret = std::min(ret, distance[r][c]);
                    }

                    for (const auto& [dr, dc] : dirs) {
                        int x = r + dr, y = c + dc;
                        if (x < 0 || m <= x || y < 0 || n <= y) {
                            continue;
                        }
                        if (grid[x][y] != empty) {
                            continue;
                        }
                        grid[x][y] -= 1;
                        q.emplace(x, y);
                    }
                }
            }
        };

        int empty = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    bfs(r, c, empty--);
                }
            }
        }

        return ret == INT_MAX ? -1 : ret;
    }

    int shortestDistance(vector<vector<int>>& grid) {
        //return f1(grid);
        //return f2(grid);
        return f3(grid);
    }
};
