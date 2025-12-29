class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs.empty() ? 0 : strs[0].size();

        int ret = 0;
        for (int c = 0; c < n; ++c) {
            for (int r = 1; r < m; ++r) {
                if (strs[r - 1][c] > strs[r][c]) {
                    ++ret;
                    break;
                }
            }
        }

        return ret;
    }
};
