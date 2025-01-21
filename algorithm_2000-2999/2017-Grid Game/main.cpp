class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long topSum = std::accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long btmSum = 0;

        long long ret = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            topSum -= grid[0][i];
            ret = std::min(ret, std::max(topSum, btmSum));
            btmSum += grid[1][i];
        }

        return ret;
    }
};
