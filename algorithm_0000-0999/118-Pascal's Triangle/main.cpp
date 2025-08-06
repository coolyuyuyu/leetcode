class Solution {
public:
    vector<vector<int>> byDP(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int r = 0; r < numRows; ++r) {
            ret[r].resize(r + 1);
            for (int c = 0; c < (r / 2 + 1); ++c) {
                if (c == 0) {
                    ret[r][c] = ret[r][r - c] = 1;
                }
                else {
                    ret[r][c] = ret[r][r - c] = ret[r - 1][c - 1] + ret[r - 1][c];
                }
            }
        }

        return ret;
    }

    vector<vector<int>> byMath(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int r = 0; r < numRows; ++r) {
            ret[r].resize(r + 1);
            for (int c = 0; c < (r / 2 + 1); ++c) {
                if (c == 0) {
                    ret[r][c] = ret[r][r - c] = 1;
                }
                else {
                    ret[r][c] = ret[r][r - c] = ret[r][c - 1] * (r - c + 1) / c;
                }
            }
        }

        return ret;
    }

    vector<vector<int>> generate(int numRows) {
        //return byDP(numRows);
        return byMath(numRows);
    }
};
