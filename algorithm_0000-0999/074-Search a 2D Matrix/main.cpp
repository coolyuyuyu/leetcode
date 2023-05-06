class Solution {
public:
    size_t lower_bound(vector<vector<int>>& matrix, int target) {
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
    }

    size_t lower_bound(vector<int>& nums, int target) {
        size_t lo = 0, hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        return lo;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t r = lower_bound(matrix, target);
        if (r == 0 && target < matrix[r][0]) {
            return false;
        }
        else if (r < matrix.size() && matrix[r][0] == target) {
            return true;
        }
        --r;

        size_t c = lower_bound(matrix[r], target);
        return c != matrix[r].size() && matrix[r][c] == target;
    }
};
