class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ret = 0;

        int minAbsVal = INT_MAX;
        int negCnt = 0;
        for (const auto& row : matrix) {
            for (int val : row) {
                negCnt += (val < 0);
                int absVal = std::abs(val);
                minAbsVal = std::min(minAbsVal, absVal);
                ret += absVal;
            }
        }
        if (negCnt & 1) {
            ret -= 2 * minAbsVal;
        }

        return ret;
    }
};
