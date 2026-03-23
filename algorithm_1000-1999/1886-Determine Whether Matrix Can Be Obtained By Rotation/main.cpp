class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        bitset<4> flags("1111");
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] != target[r][c]) { flags[0] = false; } // rotate 0
                if (mat[c][n - r - 1] != target[r][c]) { flags[1] = false; } // rotate 90
                if (mat[n - r - 1][n - c - 1] != target[r][c]) { flags[2] = false; } // rotate 180
                if (mat[n - c - 1][r] != target[r][c]) { flags[3] = false; } // rotate 270

                if (flags.none()) {
                    return false;
                }
            }
        }

        return true;
    }
};
