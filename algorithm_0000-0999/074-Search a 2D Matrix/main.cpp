class Solution {
public:
    // Time: O(logMN)
    bool bsearch(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        for (int lo = 0, hi = m * n - 1; lo <= hi;) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / n][mid % n] < target) {
                lo = mid + 1;
            }
            else if (matrix[mid / n][mid % n] == target) {
                return true;
            }
            else {
                hi = mid - 1;
            }
        }

        return false;
    }

    // Time: O(M + N)
    bool lsearch(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();

        for (int r = 0, c = n - 1; r < m && 0 <= c;) {
            if (matrix[r][c] < target) {
                ++r;
            }
            else if (matrix[r][c] == target) {
                return true;
            }
            else {
                --c;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //return bsearch(matrix, target);
        return lsearch(matrix, target);
    }
};
