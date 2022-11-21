class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze.empty() ? 0 : maze.front().size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        queue<tuple<int, int, int>> q;
        q.emplace(entrance[0], entrance[1], 0);

        int minSteps = INT_MAX;
        while (!q.empty()) {
            tuple<int, int, int> t = q.front();
            q.pop();

            int r = std::get<0>(t), c = std::get<1>(t);
            int steps = std::get<2>(t);

            if (maze[r][c] == '+') {

                continue;
            }
            else if (dp[r][c] <= steps) {
                continue;
            }
            dp[r][c] = steps;

            if (r == 0 || (r + 1) == m || c == 0 || (c + 1) == n) {
                if (r != entrance[0] || c != entrance[1]) {
                    return steps;
                }
            }

            if (0 < c) { // lft
                q.emplace(r, c - 1, steps + 1);
            }
            if (0 < r) { // top
                q.emplace(r - 1, c, steps + 1);
            }
            if ((c + 1) < n) { // rht
                q.emplace(r, c + 1, steps + 1);
            }
            if ((r + 1) < m) { // btm
                q.emplace(r + 1, c, steps + 1);
            }
        }

        return -1;
    }
};
