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

    vector<vector<int>> generate(int numRows) {
        return generate_BruteForce(numRows);
    }
};
