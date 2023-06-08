class Solution {
public:
    // Time: O(M + N)
    int linearSearch(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        size_t ret = 0;
        for (size_t r = m, c = 0; 0 < r--;) {
            while (c < n && 0 <= grid[r][c]) {
                ++c;
            }
            ret += (n - c);
        }

        return ret;
    }

    // Time: W(MlogN)
    int binarySearch(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        std::function<size_t(const vector<int>&, size_t)> firstNegative = [&](const vector<int>& nums, size_t lo) {
            for (size_t hi = n; lo < hi;) {
                size_t mid = lo + (hi - lo) / 2;
                if (nums[mid] < 0) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }

            return lo;
        };

        size_t ret = 0;
        for (size_t r = m, c = 0; 0 < r--;) {
            c = firstNegative(grid[r], c);
            ret += (n - c);
        }

        return ret;
    }

    int countNegatives(vector<vector<int>>& grid) {
        //return linearSearch(grid);
        return binarySearch(grid);
    }
};
