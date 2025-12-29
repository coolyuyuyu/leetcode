class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs.empty() ? 0 : strs[0].size();

        int ret = 0;

        vector<int> p(m, 0);
        for (int c = 0; c < n; ++c) {
            vector<int> p2 = p;
            bool f = true;
            for (int r = 1; r < m; ++r) {
                if (p[r] == 1) { continue; }
                if (strs[r - 1][c] < strs[r][c]) {
                    p2[r] = 1;
                }
                else if (strs[r - 1][c] == strs[r][c]) {
                    p2[r] = 0;
                }
                else {
                    f = false;
                }
            }
            if (f) {
                p = p2;
            }
            else {
                ++ret;
            }
        }

        return ret;
    }
};
