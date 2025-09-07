class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();

        vector<vector<int>> distances(4, vector<int>(n, -1));

        int rhtMost[] = {-1, 0, 0, 0};
        for (int i = 0; i < n; ++i) {
            int color = colors[i];
            for (int j = rhtMost[color]; j <= i; ++j) {
                distances[color][j] = i - j;
            }
            rhtMost[color] = i + 1;
        }

        int lftMost[] = {-1, n - 1, n - 1, n - 1};
        for (int i = n - 1; i >= 0; --i) {
            int color = colors[i];
            for (int j = lftMost[color]; j >= i; --j) {
                if (distances[color][j] == -1 || (j - i) < distances[color][j])
                distances[color][j] = j - i;
            }
            lftMost[color] = i - 1;
        }

        int m = queries.size();
        vector<int> ret(m);
        for (int k = 0; k < m; ++k) {
            int i = queries[k][0], c = queries[k][1];
            ret[k] = distances[c][i];
        }

        return ret;
    }
};
