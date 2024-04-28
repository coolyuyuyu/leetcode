class Solution {
public:
    bool check(vector<vector<char>>& grid, int r, int c) {
        unordered_map<char, int> cnts;
        ++cnts[grid[r][c]];
        ++cnts[grid[r][c + 1]];
        ++cnts[grid[r + 1][c]];
        ++cnts[grid[r + 1][c + 1]];
        return cnts['B'] >= 3 || cnts['W'] >= 3;
    }

    bool canMakeSquare(vector<vector<char>>& grid) {
        if (check(grid, 0, 0)) {
            return true;
        }
        if (check(grid, 0, 1)) {
            return true;
        }
        if (check(grid, 1, 0)) {
            return true;
        }
        if (check(grid, 1, 1)) {
            return true;
        }
        return false;
    }
};
