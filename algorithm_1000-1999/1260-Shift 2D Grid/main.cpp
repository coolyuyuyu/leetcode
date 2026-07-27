class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rowCnt = grid.size(), colCnt = grid[0].size();
        int n = rowCnt * colCnt;

        std::function<void(int, int)> swapCell = [&](int i, int j) {
            std::swap(grid[i / colCnt][i % colCnt], grid[j / colCnt][j % colCnt]);
        };

        for (int first = 0, last = n, middle = (n - k % n) % n, next = middle; first != next;) {
            swapCell(first++, next++);
            if (next == last) { next = middle; }
            else if (first == middle) { middle = next; }
        }

        return grid;
    }
};
