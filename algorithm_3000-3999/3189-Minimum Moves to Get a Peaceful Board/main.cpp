class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int n = rooks.size();

        int rows[n], cols[n];
        for (int i = 0; i < n; ++i) {
            rows[i] = rooks[i][0];
            cols[i] = rooks[i][1];
        }

        int ret = 0;

        std::sort(rows, rows + n);
        for (int i = 0; i < n; ++i) {
            ret += std::abs(rows[i] - i);
        }
        std::sort(cols, cols + n);
        for (int i = 0; i < n; ++i) {
            ret += std::abs(cols[i] - i);
        }

        return ret;
    }
};
