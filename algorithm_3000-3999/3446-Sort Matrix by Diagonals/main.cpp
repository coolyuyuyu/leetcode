class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int nums[n];

        for (int k = 0; k < n; ++k) {
            for (int r = k, c = 0, i = 0; r < n; ++r, ++c) {
                nums[i++] = grid[r][c];
            }
            std::sort(nums, nums + (n - k), std::greater<int>());
            for (int r = k, c = 0, i = 0; r < n; ++r, ++c, ++i) {
                grid[r][c] = nums[i];
            }
        }
        for (int k = 1; k < n; ++k) {
            for (int r = 0, c = k, i = 0; c < n; ++r, ++c) {
                nums[i++] = grid[r][c];
            }
            std::sort(nums, nums + (n - k), std::less<int>());
            for (int r = 0, c = k, i = 0; c < n; ++r, ++c, ++i) {
                grid[r][c] = nums[i];
            }
        }

        return grid;
    }
};
