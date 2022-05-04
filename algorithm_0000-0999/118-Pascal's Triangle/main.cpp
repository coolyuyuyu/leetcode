class Solution {
public:
    vector<vector<int>> dp(size_t numRows) {
        if (numRows == 0) {
            return {};
        }

        vector<vector<int>> ret(numRows);
        ret[0]= {1};
        for (size_t i = 1; i < numRows; ++i) {
            ret[i].resize(i + 1);

            ret[i][0] = 1;
            for (size_t j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
            ret[i][i] = 1;
        }

        return ret;
    }

    vector<vector<int>> math(size_t numRows) {
        if (numRows == 0) {
            return {};
        }

        vector<vector<int>> ret(numRows);
        ret[0]= {1};
        for (size_t i = 1; i < numRows; ++i) {
            ret[i].resize(i + 1);

            ret[i][0] = 1;
            for (size_t k = 1; k < i; ++k) {
                ret[i][k] = ret[i][k - 1] * (i - k + 1) / k;
            }
            ret[i][i] = 1;
        }

        return ret;
    }

    vector<vector<int>> generate(int numRows) {
        //return dp(numRows);
        return math(numRows);
    }
};