class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();

        vector<vector<int>> ret(m - k + 1, vector<int>(n - k + 1));
        for (int r = 0; r + k <= m; ++r) {
            for (int c = 0; c + k <= n; ++c) {
                vector<int> nums;
                for (int i = 0; i < k; ++i) {
                    for (int j = 0; j < k; ++j) {
                        nums.push_back(grid[r + i][c + j]);
                    }
                }
                std::sort(nums.begin(), nums.end());
                nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

                if (nums.size() == 1) { ret[r][c] = 0; }
                else {
                    int minDiff = INT_MAX;
                    for (int x = 1; x < nums.size(); ++x) {
                        minDiff = std::min(minDiff, nums[x] - nums[x - 1]);
                    }
                    ret[r][c] = minDiff;
                }
            }
        }

        return ret;
    }
};
