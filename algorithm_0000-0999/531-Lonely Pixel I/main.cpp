class Solution {
public:
    // Time: O(m * n), Space: O(m * n)
    int f1(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture.empty() ? 0 : picture[0].size();

        vector<int> rowBlacks(m, 0), colBlacks(n, 0);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (picture[r][c] == 'B') {
                    ++rowBlacks[r];
                    ++colBlacks[c];
                }
            }
        }

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (picture[r][c] == 'B' && rowBlacks[r] == 1 && colBlacks[c] == 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }

    // Time: O(m * n), Space: O(1)
    int f2(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture.empty() ? 0 : picture[0].size();

        std::function<bool(int, int)> check = [&](int x, int y) {
            int cnt = 0;
            for (int r = 0; r < m; ++r) {
                cnt += (picture[r][y] == 'B') ? 1 : 0;
            }
            for (int c = 0; c < n; ++c) {
                cnt += (c != y && picture[x][c] == 'B') ? 1 : 0;
            }

            return picture[x][y] == 'B' && cnt == 1;
        };

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            ret += check(r, 0) ? 1 : 0;
        }
        for (int c = 1; c < n; ++c) {
            ret += check(0, c) ? 1 : 0;
        }

        for (int r = 0; r < m; ++r) {
            picture[r][0] = (picture[r][0] == 'B') ? 1 : 0;
        }
        for (int c = 0; c < n; ++c) {
            picture[0][c] = (picture[0][c] == 'B') ? 1 : 0;
        }

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (picture[r][c] == 'B') {
                    ++picture[r][0];
                    ++picture[0][c];
                }
            }
        }

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (picture[r][c] == 'B' && picture[r][0] == 1 && picture[0][c] == 1) {
                    ++ret;
                }
            }
        }

        return ret;
    }

    int findLonelyPixel(vector<vector<char>>& picture) {
        //return f1(picture);
        return f2(picture);
    }
};
