class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int maxDist = std::max({rCenter + cCenter, rCenter + cols - cCenter - 1, rows - rCenter - 1 + cols - cCenter - 1, rows - rCenter - 1 + cCenter});
        vector<int> distCnts(maxDist + 1, 0);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                ++distCnts[abs(r - rCenter) + abs(c - cCenter)];
            }
        }
        std::partial_sum(distCnts.begin(), distCnts.end(), distCnts.begin());

        vector<vector<int>> ans(distCnts.back());
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                ans[--distCnts[abs(r - rCenter) + abs(c - cCenter)]] = {r, c};
            }
        }
        return ans;
    }
};
