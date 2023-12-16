class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        vector<int> rows, cols;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    rows.push_back(r);
                    cols.push_back(c);
                }
            }
        }

        // rows is already sorted
        int rMedian = rows[rows.size() / 2];
        std::nth_element(cols.begin(), cols.begin() + cols.size() / 2, cols.end());
        int cMedian = cols[cols.size() / 2];
        std::function<int(const vector<int>&, int)> computeDists = [](const vector<int>& nums, int target) {
            int ret = 0;
            for (int num : nums) {
                ret += abs(target - num);
            }

            return ret;
        };

        return computeDists(rows, rMedian) + computeDists(cols, cMedian);
    }
};
