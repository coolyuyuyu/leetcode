class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze.empty() ? 0 : maze[0].size();

        bool visited[m][n];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }
        queue<pair<int, int>> q;

        visited[entrance[0]][entrance[1]] = true;
        q.emplace(entrance[0], entrance[1]);

        for(int step = 0; !q.empty(); ++step) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();
                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { cout << "\t1" << endl; continue; }
                    if (maze[x][y] == '+') { cout << "\t2" << endl;  continue; }
                    if (visited[x][y]) { cout << "\t3" << endl;  continue; }

                    if ((x == 0 || x + 1 == m || y == 0 || y + 1 == n) && (x != entrance[0] || y != entrance[1])) {
                        return step + 1;
                    }

                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }
        }

        return -1;
    }
};
