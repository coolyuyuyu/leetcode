class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ret = 0;
        unordered_set<int> rows, cols;
        for (int i = queries.size(); 0 < i--;) {
            if (queries[i][0] == 0) {
                if (rows.insert(queries[i][1]).second) {
                    ret += (n - cols.size()) * queries[i][2];
                }
            }
            else {
                if (cols.insert(queries[i][1]).second) {
                    ret += (n - rows.size()) * queries[i][2];
                }
            }
        }

        return ret;
    }
};
