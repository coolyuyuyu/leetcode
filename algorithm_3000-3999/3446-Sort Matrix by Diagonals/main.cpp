class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int nums[n];

        for (int k = 1; k < n; ++k) {
            int len = 0;
            for (int r = 0, c = k;  c < n; ++r, ++c) {
                nums[len++] = grid[r][c];
            }
            sort(nums, nums + len);
            for (int r = 0, c = k, i = 0; i < len; ++r, ++c, ++i) {
                grid[r][c] = nums[i];
            }
        }
        for (int k = 0; k < n; ++k) {
            int len = 0;
            for (int r = k, c = 0;  r < n; ++r, ++c) {
                nums[len++] = grid[r][c];
            }
            sort(nums, nums + len, std::greater<int>());
            for (int r = k, c = 0, i = 0; i < len; ++r, ++c, ++i) {
                grid[r][c] = nums[i];
            }
        }

        return grid;
    }
};
