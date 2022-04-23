class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        size_t m = strs.size(), n = strs.empty() ? 0 : strs.front().size();
        
        size_t c = 0;
        for (size_t j = 0; j < n; ++j) {
            for (size_t i = 1; i < m; ++i) {
                if (strs[i][j] < strs[i - 1][j]) {
                    c += 1;
                    break;
                }
            }
        }
        return c;
    }
};
