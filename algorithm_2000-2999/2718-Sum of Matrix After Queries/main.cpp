class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ret = 0;
        vector<bool> rowEmpty(n, true), colEmpty(n, true);
        int rowRemaining = n, colRemaining = n;
        for (int i = queries.size(); 0 < i--;) {
            if (queries[i][0] == 0) {
                if (rowEmpty[queries[i][1]]) {
                    rowEmpty[queries[i][1]] = false;
                    ret += (colRemaining) * queries[i][2];
                    --rowRemaining;
                }
            }
            else {
                if (colEmpty[queries[i][1]]) {
                    colEmpty[queries[i][1]] = false;
                    ret += (rowRemaining) * queries[i][2];
                    --colRemaining;
                }
            }
        }

        return ret;
    }
};
