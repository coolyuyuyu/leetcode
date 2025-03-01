class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size(), m = grid.empty() ? 0 : grid[0].size();

        priority_queue<pair<int, int>> pq;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                pq.emplace(grid[r][c], r);
            }
        }

        long long ret = 0;
        while (k > 0) {
            auto [num, r] = pq.top();
            pq.pop();

            if (limits[r] == 0) {
                continue;
            }

            --k;
            --limits[r];
            ret += num;
        }

        return ret;
    }
};
