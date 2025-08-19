class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        vector<int> indexes(m, 0);
        int ret = INT_MIN;
        for (int r = 0, cnt = 0; cnt < m; r = (r + 1) % m) {
            while (indexes[r] < n && mat[r][indexes[r]] < ret) {
                ++indexes[r];
            }
            if (indexes[r] >= n) {
                return -1;
            }

            if (mat[r][indexes[r]] == ret) {
                ++cnt;
            }
            else {
                ret = mat[r][indexes[r]];
                cnt =1;
            }
        }

        return ret;
    }
};
