/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        vector<pair<int, int>> diffs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        bool visited[201][401];
        for (int r = 0; r < 201; ++r) {
            for (int c = 0; c < 401; ++c) {
                visited[r][c] = false;
            }
        }
        std::function<void(int, int, int)> dfs = [&](int r, int c, int dir) {
            robot.clean();
            for (int k = 0; k < diffs.size(); ++k) {
                dir = (dir + 1) % diffs.size();
                const auto& [dr, dc] = diffs[dir];
                int x = r + dr, y = c + dc;
                robot.turnRight();
                if (!visited[x][y] && robot.move()) {
                    visited[x][y] = true;
                    dfs(x, y, dir);
                    robot.turnRight();
                    robot.turnRight();
                    robot.move();
                    robot.turnRight();
                    robot.turnRight();
                }
            }
        };
        int srcR = 100, srcC = 200;
        visited[srcR][srcC] = true;
        dfs(srcR, srcC, 0);
    }
};
