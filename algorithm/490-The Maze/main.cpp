class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        size_t rowCnt = maze.size(), colCnt = maze.empty() ? 0 : maze.front().size();
        vector<vector<bool>> visited(rowCnt, vector<bool>(colCnt, false));
        pair<size_t, size_t> bgn = {start[0], start[1]}, end = {destination[0], destination[1]};

        queue<pair<size_t, size_t>> positions;
        positions.emplace(bgn.first, bgn.second);
        while (!positions.empty()) {
            pair<size_t, size_t> pos = positions.front();
            positions.pop();

            if (visited[pos.first][pos.second]) {
                continue;
            }
            else if (pos == end) {
                return true;
            }
            else {
                visited[pos.first][pos.second] = true;

                pair<size_t, size_t> posTmp;

                // lft
                posTmp = pos;
                while (0 < posTmp.second && maze[posTmp.first][posTmp.second - 1] == 0) {
                    --(posTmp.second);
                }
                if (posTmp != pos) {
                    positions.emplace(posTmp.first, posTmp.second);
                }

                // upr
                posTmp = pos;
                while (0 < posTmp.first && maze[posTmp.first - 1][posTmp.second] == 0) {
                    --(posTmp.first);
                }
                if (posTmp != pos) {
                    positions.emplace(posTmp.first, posTmp.second);
                }

                // rht
                posTmp = pos;
                while (posTmp.second + 1 < colCnt && maze[posTmp.first][posTmp.second + 1] == 0) {
                    ++(posTmp.second);
                }
                if (posTmp != pos) {
                    positions.emplace(posTmp.first, posTmp.second);
                }

                // btm
                posTmp = pos;
                while (posTmp.first + 1 < rowCnt && maze[posTmp.first + 1][posTmp.second] == 0) {
                    ++(posTmp.first);
                }
                if (posTmp != pos) {
                    positions.emplace(posTmp.first, posTmp.second);
                }
            }
        }

        return false;
    }
};