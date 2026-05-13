class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int lft = 0, rht = n - 1, top = 0, btm = m - 1; top <= btm && lft <= rht; ++top, --btm, ++lft, --rht) {
            vector<int> nums((btm - top + rht - lft) * 2);
            int i = 0;
            for (int c = lft; c < rht; ++c) {
                nums[i++] = grid[top][c];
            }
            for (int r = top; r < btm; ++r) {
                nums[i++] = grid[r][rht];
            }
            for (int c = rht; c > lft; --c) {
                nums[i++] = grid[btm][c];
            }
            for (int r = btm; r > top; --r) {
                nums[i++] = grid[r][lft];
            }

            std::rotate(nums.begin(), nums.begin() + k % nums.size(), nums.end());

            i = 0;
            for (int c = lft; c < rht; ++c) {
                grid[top][c] = nums[i++];
            }
            for (int r = top; r < btm; ++r) {
                grid[r][rht] = nums[i++];
            }
            for (int c = rht; c > lft; --c) {
                grid[btm][c] = nums[i++];
            }
            for (int r = btm; r > top; --r) {
                grid[r][lft] = nums[i++];
            }
        }

        return grid;
    }
};
