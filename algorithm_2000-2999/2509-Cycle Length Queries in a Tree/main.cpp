class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> lengths(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            int len = 1;
            for (int a = queries[i][0], b = queries[i][1]; a != b; ++len) {
                if (a < b) {
                    b /= 2;
                }
                else {
                    a /= 2;
                }
            }
            lengths[i] = len;
        }

        return lengths;
    }
};
