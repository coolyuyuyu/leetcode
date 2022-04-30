class Solution {
public:
    // Time: O(M + N)
    int linearSearch(vector<vector<int>>& grid) {
        size_t row = grid.size(), col = grid.empty() ? 0 : grid.front().size();

        size_t cnt = 0;
        for (size_t r = row, c = 0; 0 < r-- && c < col;) {
            while (c < col && grid[r][c] >= 0 ) {
                ++c;
            }
            cnt += (col - c);
        }

        return cnt;
    }

    // Time: W(MlogN)
    int binarySearch(vector<vector<int>>& grid) {
        size_t row = grid.size(), col = grid.empty() ? 0 : grid.front().size();

        auto firstNegative = [&](vector<int>& row, size_t lo) -> size_t {
            size_t hi = col;
            while (lo < hi) {
                size_t mid = lo + (hi - lo) / 2;
                if (0 <= row[mid]) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }
            return lo;
        };

        size_t cnt = 0;
        for (size_t r = row, c = 0; 0 < r-- && c < col;) {
            c = firstNegative(grid[r], c);
            cnt += (col - c);
        }

        return cnt;
    }

    int countNegatives(vector<vector<int>>& grid) {
        //return linearSearch(grid);
        return binarySearch(grid);
    }
};
