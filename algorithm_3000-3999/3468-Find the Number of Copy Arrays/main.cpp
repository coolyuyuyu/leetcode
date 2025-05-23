class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int l = bounds[0][0], r = bounds[0][1];
        for (int i = 1; i < n; ++i) {
            int diff = original[i] - original[i - 1];
            l += diff, r += diff;

            int u = bounds[i][0], v = bounds[i][1];
            l = std::max(l, u);
            r = std::min(r, v);
            if (l > r) {
                return 0;
            }
        }

        return r - l + 1;
    }
};
