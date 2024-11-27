class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int dists[n][n];
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                dists[u][v] = (u <= v ? (v - u) : INT_MAX / 3);
            }
        }

        int m = queries.size();
        vector<int> ret(m);
        for (int i = 0; i < m; ++i) {
            int a = queries[i][0], b = queries[i][1];
            for (int u = 0; u < n; ++u) {
                for (int v = b; v < n; ++v) {
                    dists[u][v] = std::min(dists[u][v], dists[u][a] + 1 + dists[b][v]);
                }
            }

            ret[i] = dists[0][n - 1];
        }

        return ret;
    }
};
