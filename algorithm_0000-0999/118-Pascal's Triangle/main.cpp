class Solution {
public:
    vector<vector<int>> generate_BruteForce(int numRows) {
        if (numRows == 0) {
            return {};
        }

        vector<vector<int>> ret(numRows);
        ret[0].push_back(1);
        for (size_t i = 1; i < numRows; ++i) {
            ret[i].push_back(1);
            for (size_t j = 1; j < ret[i - 1].size(); ++j) {
                ret[i].push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            }
            ret[i].push_back(1);
        }

        return ret;
    }

    vector<vector<int>> generate_Math(int numRows) {
        vector<vector<int>> ret(numRows);
        for (size_t n = 0; n < numRows; ++n) {
            ret[n].push_back(1);
            for (size_t k = 1; k <= n; ++k) {
                ret[n].push_back(static_cast<long long int>(ret[n].back()) * (n - k + 1) / k);
            }
        }

        return ret;
    }

    vector<vector<int>> generate(int numRows) {
        //return generate_BruteForce(numRows);
        return generate_Math(numRows);
    }
};
