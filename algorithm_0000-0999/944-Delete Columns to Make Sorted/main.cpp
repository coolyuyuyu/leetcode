class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        size_t m = strs.size(), n = strs[0].size();

        size_t ret = 0;
        for (size_t j = 0; j < n; ++j) {
            for(size_t i = 1; i < m; ++i) {
                if (strs[i - 1][j] > strs[i][j]) {
                    ++ret;
                    break;
                }
            }
        }

        return ret;

    }
};
