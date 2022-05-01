class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        size_t n = mat.size();

        bitset<4> bits("1111");
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (bits[0] && target[i][j] != mat[i][j]) { // 0
                    bits[0] = false;
                }
                if (bits[1] && target[i][j] != mat[j][n - i - 1]) { // 90
                    bits[1] = false;
                }
                if (bits[2] && target[i][j] != mat[n - i - 1][n - j - 1]) { // 180
                    bits[2] = false;
                }
                if (bits[3] && target[i][j] != mat[n - j - 1][i]) { // 270
                    bits[3] = false;
                }

                if (bits.none()) {
                    return false;
                }
            }
        }

        return true;
    }
};
