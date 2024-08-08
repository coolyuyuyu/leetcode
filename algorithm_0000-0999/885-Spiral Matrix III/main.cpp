;class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int r = rStart, c = cStart;
        vector<vector<int>> ret = {{r, c}};
        for (int i = 0, d = 0; ret.size() < rows * cols ; ++i, d = (d + 1) % 4) {
            int step = i / 2 + 1;
            const auto& [dr, dc] = dirs[d];
            for (int j = 0; j < step; ++j) {
                r += dr, c += dc;
                if (r >= 0 && r < rows && 0 <= c && c < cols ) {
                    ret.push_back({r, c});
                }
            }
        }

        return ret;
    }
};
