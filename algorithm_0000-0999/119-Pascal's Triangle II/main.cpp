class Solution {
public:
    vector<int> dynamicProgramming(int rowIndex) {
        // dp[i]: the ith elelement of Pascal's triangle with rowIndex as rowIndex
        vector<int> dp(rowIndex + 1);
        for (int r = 0; r <= rowIndex; ++r) {
            dp[r] = 1;
            for (int c = r - 1; c >= 1; --c) {
                dp[c] = dp[c] + dp[c - 1];
            }
            dp[0] = 1;
        }

        return dp;
    }

    vector<int> math(int rowIndex) {
        // dp[i]: the ith elelement of Pascal's triangle with rowIndex as rowIndex
        vector<int> dp(rowIndex + 1);
        dp[0] = 1;
        for (int c = 1; c <= rowIndex / 2; ++c) {
            dp[rowIndex - c] = dp[c] = (long long)dp[c - 1] * (rowIndex - c + 1) / c;
        }
        dp[rowIndex] = 1;

        return dp;
    }

    vector<int> getRow(int rowIndex) {
        //return dynamicProgramming(rowIndex);
        return math(rowIndex);
    }
};
