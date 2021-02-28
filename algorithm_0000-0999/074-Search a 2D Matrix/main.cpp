class Solution {
public:
    int binarySearch(const vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return -1;
    }

    int binarySearch(const vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid].empty()) {
                return false;
            }

            if (matrix[mid].front() <= target && target <= matrix[mid].back()) {
                return mid;
            }
            else if (matrix[mid].back() < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = binarySearch(matrix, target);
        if (row < 0) {
            return false;
        }

        int col = binarySearch(matrix[row], target);
        if (col < 0) {
            return false;
        }

        return true;
    }
};