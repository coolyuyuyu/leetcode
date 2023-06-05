class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<int> rowFilled(n, false), colFilled(n, false);
        int rowLeft = n, colLeft = n;

        long long ret = 0;
        for (size_t i = queries.size(); 0 < i--;) {
            int type = queries[i][0], idx = queries[i][1], val = queries[i][2];
            if (type == 0) {
                if (!rowFilled[idx]) {
                    rowFilled[idx] = true;
                    ret += colLeft * val;
                    --rowLeft;
                }
            }
            else {
                if (!colFilled[idx]) {
                    colFilled[idx] = true;
                    ret += rowLeft * val;
                    --colLeft;
                }
            }
        }

        return ret;
    }
};
