class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        set<pair<size_t, size_t>> points;
        size_t rowCnt = rooms.size(), colCnt = rooms.empty() ? 0 : rooms.front().size();
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (rooms[row][col] == 0) {
                    points.emplace(row, col);
                }
            }
        }

        // BFS
        int distance = 0;
        while (!points.empty()) {
            for (const pair<size_t, size_t>& point : points) {
                size_t row = point.first, col = point.second;
                rooms[row][col] = distance;
            }

            set<pair<size_t, size_t>> pointsTmp;
            for (const pair<size_t, size_t>& point : points) {
                size_t row = point.first, col = point.second;

                // lft
                if (0 < row && rooms[row - 1][col] == INT_MAX) {
                    pointsTmp.emplace(row - 1, col);
                }

                // upr
                if (0 < col && rooms[row][col - 1] == INT_MAX) {
                    pointsTmp.emplace(row, col - 1);
                }

                // rht
                if (col + 1 < colCnt && rooms[row][col + 1] == INT_MAX) {
                    pointsTmp.emplace(row, col + 1);
                }

                // btm
                if (row + 1 < rowCnt && rooms[row + 1][col] == INT_MAX) {
                    pointsTmp.emplace(row + 1, col);
                }
            }
            points.swap(pointsTmp);

            ++distance;
        }
    }
};