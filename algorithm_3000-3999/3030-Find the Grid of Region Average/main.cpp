class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size(), n = image.empty() ? 0 : image[0].size();
        vector<vector<int>> sum(m, vector<int>(n)), cnt(m, vector<int>(n));

        std::function<void(int, int)> accumulateIfRegion = [&](int r, int c) {
            int regionSum = 0;
            for (int x = r; x < r + 3; ++x) {
                for (int y = c; y < c + 3; ++y) {
                    if (x > r && std::abs(image[x][y] - image[x - 1][y]) > threshold) {
                        return;
                    }
                    if (y > c && std::abs(image[x][y] - image[x][y - 1]) > threshold) {
                        return;
                    }
                    regionSum += image[x][y];
                }
            }
            int regionAvg = regionSum / 9;

            for (int x = r; x < r + 3; ++x) {
                for (int y = c; y < c + 3; ++y) {
                    sum[x][y] += regionAvg;
                    cnt[x][y] += 1;
                }
            }
        };
        for (int r = 0; r + 2 < m; ++r) {
            for (int c = 0; c + 2 < n; ++c) {
                accumulateIfRegion(r, c);
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                sum[r][c] = cnt[r][c] ? (sum[r][c] / cnt[r][c]) : image[r][c];
            }
        }

        return sum;
    }
};
