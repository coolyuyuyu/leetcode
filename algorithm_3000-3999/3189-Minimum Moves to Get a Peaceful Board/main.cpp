class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int n = rooks.size();

        int rows[n], cols[n];
        for (int i = 0; i < n; ++i) {
            rows[i] = rooks[i][0];
            cols[i] = rooks[i][1];
        }
        std::sort(rows, rows + n);
        std::sort(cols, cols + n);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += abs(i - rows[i]);
            ret += abs(i - cols[i]);
        }

        return ret;
    }
};
