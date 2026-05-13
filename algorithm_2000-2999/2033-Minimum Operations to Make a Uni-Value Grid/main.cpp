class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<int> nums(m * n);
        for (int r = 0, i = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                nums[i++] = grid[r][c];
            }
        }
        std::sort(nums.begin(), nums.end());

        int median = nums[m * n / 2];

        int ret = 0;
        for (int num : nums) {
            int diff = std::abs(num - median);
            if (diff % x != 0) {
                return -1;
            }
            ret += diff / x;
        }

        return ret;
    }
};
