class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        size_t rowCnt = grid.size(), colCnt = (grid.empty() ? 0 : grid.front().size()), n = rowCnt * colCnt;

        auto swap4Grid = [&grid, &colCnt](size_t index1, size_t index2) {
            swap(grid[index1 / colCnt][index1 % colCnt], grid[index2 / colCnt][index2 % colCnt]);
        };

        size_t front = 0, last = n, middle = (n - k % n) % n;
        for (size_t next = middle; front != next;) {
            swap4Grid(front++, next++);
            if (next == last) {
                next = middle;
            }
            else if (front == middle) {
                middle = next;
            }
        }

        return grid;
    }
};
