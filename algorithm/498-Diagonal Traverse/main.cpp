class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int xLen = matrix.size(), yLen = matrix.empty() ? 0 : matrix.front().size();

        vector<int> nums(xLen * yLen);
        size_t index = 0;
        for (int x = 0, y = 0, dx = -1, dy = 1; index < nums.size(); dx = -dx, dy = -dy) {
            for (; 0 <= x && x < xLen && 0 <= y && y < yLen; x += dx, y += dy) {
                nums[index++] = matrix[x][y];
            }
            x -= dx, y -= dy;

            if (dx == -1) {
                if (y + 1 < yLen) {
                    y += 1;
                }
                else {
                    x += 1;
                }
            }
            else {
                assert(dx == 1);
                if (x + 1 < xLen) {
                    x += 1;
                }
                else {
                    y += 1;
                }
            }
        }

        return nums;
    }
};