class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int m = points.size(), n = queries.size();

        vector<int> ret(n, 0);
        for (int j = 0; j < n; ++j) {
            int cx = queries[j][0], cy = queries[j][1], cr = queries[j][2];
            for (int i = 0; i < m; ++i) {
                int x = points[i][0], y = points[i][1];
                if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= cr * cr) {
                    ret[j] += 1;
                }
            }
        }

        return ret;
    }
};
