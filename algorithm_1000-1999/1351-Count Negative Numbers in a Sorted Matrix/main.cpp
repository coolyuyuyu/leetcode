class Solution {
public:
    // Time: O(m + n)
    int lsearch(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int ret = 0;
        for (int i = m, j = 0; 0 < i--;) {
            for (; j < n && grid[i][j] >= 0; ++j) {
                ;
            }

            ret += (n - j);
        }

        return ret;
    }

    // Time: O(m * logn)
    int bsearch(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int ret = 0;
        for (int i = m, j = 0; 0 < i--;) {
            int lo = j, hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (grid[i][mid] < 0) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
            j = lo;

            ret += (n - j);
        }

        return ret;
    }

    // Time: O(m * logn)
    int bsearch_stdlib(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        int ret = 0;
        for (int i = m, j = 0; 0 < i--;) {
            j = std::distance(grid[i].begin(), std::upper_bound(grid[i].begin() + j, grid[i].end(), 0, std::greater<int>()));

            ret += (n - j);
        }

        return ret;
    }

    int countNegatives(vector<vector<int>>& grid) {
        //return lsearch(grid);
        //return bsearch(grid);
        return bsearch_stdlib(grid);
    }
};
