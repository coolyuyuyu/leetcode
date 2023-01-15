class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));

        for (auto& query : queries) {
            for (int r = query[0]; r <= query[2]; ++r) {
                ++diff[r][query[1]];
                if ((query[3] + 1) < n) {
                    --diff[r][query[3] + 1];
                }
            }
        }

        for (int r = 0; r < n; ++r) {
            int sum = 0;
            for (int c = 0; c < n; ++c) {
                sum += diff[r][c];
                diff[r][c] = sum;
            }
        }

        return diff;
    }
};
