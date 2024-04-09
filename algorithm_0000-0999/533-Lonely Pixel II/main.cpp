class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size(), n = picture.empty() ? 0 : picture[0].size();

        vector<vector<int>> colsets(m);
        vector<vector<int>> rowsets(n);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (picture[r][c] == 'B') {
                    colsets[r].push_back(c);
                    rowsets[c].push_back(r);
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (picture[r][c] == 'B' && colsets[r].size() == target && rowsets[c].size() == target) {
                    bool lonely = true;
                    for (const auto& row : rowsets[c]) {
                        if (colsets[row] != colsets[r]) {
                            lonely = false;
                        }
                    }
                    if (lonely) {
                        ++ret;
                    }
                }
            }
        }

        return ret;
    }
};
