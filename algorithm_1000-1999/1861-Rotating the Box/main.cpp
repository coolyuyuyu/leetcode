class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box.empty() ? 0 : box[0].size();

        vector<vector<char>> ret(n, vector<char>(m, '.'));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int cnt = 0, i = c;
                for (; i < n && box[r][i] != '*'; ++i) {
                    if (box[r][i] == '#') {
                        ++cnt;
                    }
                }

                if (i != n) {
                    ret[i][m - 1 - r] = '*';
                }
                for (int j = 1; j <= cnt; ++j) {
                    ret[i - j][m - 1- r] = '#';
                }

                c = i;
            }
        }

        return ret;
    }
};
