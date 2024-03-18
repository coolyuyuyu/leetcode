/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    vector<tuple<char, int, int>> diffs = {{'U', -1, 0}, {'R', 0, 1}, {'D', 1, 0}, {'L', 0, -1}};

    const static int m = 201, n = 201;
    int grid[m][n];
    bool visited[m][n];

    pair<int, int> src = {m / 2, n / 2};
    pair<int, int> dst;

    void dfs(int r, int c, GridMaster &master) {
        if (master.isTarget()) {
            dst = {r, c};
        }

        for (const auto& [dir, dr, dc] : diffs) {
            int x = r + dr, y = c + dc;
            if (visited[x][y]) { continue; }
            if (master.canMove(dir)) {
                visited[x][y] = true;
                grid[x][y] = master.move(dir);

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
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                grid[r][c] = 0;
                visited[r][c] = false;
            }
        }
        const auto& [srcR, srcC] = src;
        dfs(srcR, srcC, master);

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                visited[r][c] = false;
            }
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> pq;
        const auto& [dstR, dstC] = dst;
        pq.emplace(0, srcR, srcC);
        while (!pq.empty()) {
            auto [cost, r ,c] = pq.top();
            pq.pop();

            if (visited[r][c]) { continue; }
            visited[r][c] = true;

            if (r == dstR && c == dstC) { return cost; }

            for (const auto& [_, dr, dc] : diffs) {
                int x = r + dr, y = c + dc;
                if (visited[x][y]) { continue; }
                if (grid[x][y] == 0) { continue; }

                pq.emplace(cost + grid[x][y], x, y);
            }
        }

        return -1;
    }
};
