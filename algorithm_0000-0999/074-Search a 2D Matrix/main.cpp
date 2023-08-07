class Solution {
public:
    bool binarySearch2D(const vector<vector<int>>& matrix, int target) {
        std::function<size_t(const vector<vector<int>>&, int)> row_lower_bound = [](const vector<vector<int>>& matrix, int target) -> size_t {
            size_t lo = 0, hi = matrix.size();
            while (lo < hi) {
                size_t mid = lo + (hi - lo) / 2;
                if (matrix[mid][0] < target) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }

            return lo;
        };
        std::function<size_t(const vector<int>&, int)> col_lower_bound = [](const vector<int>& row, int target) -> size_t {
            size_t lo = 0, hi = row.size();
            while (lo < hi) {
                size_t mid = lo + (hi - lo) / 2;
                if (row[mid] < target) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }

            return lo;
        };

        size_t r = row_lower_bound(matrix, target);
        if (r < matrix.size() && matrix[r][0] == target) {
            return true;
        }
        else if (r == 0 && target < matrix[r][0]) {
            return false;
        }
        r--;

        const vector<int>& row = matrix[r];
        size_t c = col_lower_bound(row, target);
        return c < row.size() && row[c] == target;
    }

    bool binarySearch1D(const vector<vector<int>>& matrix, int target) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        size_t lo = 0, hi = m * n - 1;
        while (lo <= hi) {
            size_t mid = lo + (hi - lo) / 2;
            int pivot = matrix[mid / n][mid % n];
            if (pivot == target) {
                return true;
            }
            else if (pivot < target) {
                lo = mid + 1;
            }
            else {
                if (mid == 0) {
                    break;
                }
                hi = mid - 1;
            }
        }

        return false;
    }

    bool linearSearch2D(const vector<vector<int>>& matrix, int target) {
        size_t m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        for (int r = 0, c = n - 1; r < m && 0 <= c;) {
            if (matrix[r][c] == target) {
                return true;
            }
            else if (matrix[r][c] < target) {
                ++r;
            }
            else {
                --c;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //return binarySearch2D(matrix, target);
        //return binarySearch1D(matrix, target);
        return linearSearch2D(matrix, target);
    }
};
