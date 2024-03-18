/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    vector<tuple<char, int, int>> diffs = {{'U', -1, 0}, {'R', 0, 1}, {'D', 1, 0}, {'L', 0, -1}};
    int grid[1001][1001];
    bool visited[1001][1001];

    void dfs(int r, int c, GridMaster &master) {
        grid[r][c] = master.isTarget() ? 2 : 1;
        for (const auto& [dir, dr, dc] : diffs) {
            int x = r + dr, y = c + dc;
            if (visited[x][y]) { continue; }
            if (master.canMove(dir)) {
                visited[x][y] = true;
                master.move(dir);

                dfs(x, y, master);

                char oppositeDir;
                switch (dir) {
                    case 'U': oppositeDir = 'D'; break;
                    case 'R': oppositeDir = 'L'; break;
                    case 'D': oppositeDir = 'U'; break;
                    case 'L': oppositeDir = 'R'; break;
                }
                master.move(oppositeDir);
            }
        }
    }

    int findShortestPath(GridMaster &master) {
        for (int r = 0; r < 1001; ++r) {
            for (int c = 0; c < 1001; ++c) {
                grid[r][c] = 0;
                visited[r][c] = false;
            }
        }

        int srcR = 500, srcC = 500;
        visited[srcR][srcC] = true;
        dfs(srcR, srcC, master);
        grid[srcR][srcC] = -1;

        for (int r = 0; r < 1001; ++r) {
            for (int c = 0; c < 1001; ++c) {
                visited[r][c] = false;
            }
        }
        queue<pair<int, int>> q;
        visited[srcR][srcC] = true;
        q.emplace(srcR, srcC);
        for (int lvl = 0; !q.empty(); ++lvl) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [_, dr, dc] : diffs) {
                    int x = r + dr, y = c + dc;
                    if (visited[x][y]) { continue; }
                    if (grid[x][y] == 2) { return lvl + 1; }
                    if (grid[x][y] == 0) { continue; }
                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }
        }

        return -1;
    }
};
