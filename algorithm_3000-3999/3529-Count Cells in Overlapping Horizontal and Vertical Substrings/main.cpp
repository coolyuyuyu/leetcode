class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int k = pattern.size();

        // lps[i]: the maximum value k such that needle[0:k-1] == needle[i-k+1:i]
        int lps[k];
        lps[0] = 0;
        for (int i = 1; i < k; ++i) {
            int j = lps[i - 1];
            while (j > 0 && pattern[j] != pattern[i]) {
                j = lps[j - 1];
            }
            lps[i] = j + (pattern[j] == pattern[i] ? 1 : 0);
        }

        int m = grid.size(), n = grid.empty() ? 0 : grid[0].size();
        int len = m * n;

        int hPresums[len + 1], vPresums[len + 1];
        std::fill(hPresums, hPresums + len + 1, 0);
        std::fill(vPresums, vPresums + len + 1, 0);
        for (int i = 0, hj = 0, vj = 0; i < len; ++i) {
            int hr = i / n, hc = i % n;
            while ((hj > 0 && grid[hr][hc] != pattern[hj]) || hj == k) {
                hj = lps[hj - 1];
            }
            hj = hj + (grid[hr][hc] == pattern[hj] ? 1 : 0);

            if (hj == k) {
                ++hPresums[i - k + 1];
                --hPresums[i + 1];
            }

            int vr = i % m, vc = i / m;
            while ((vj > 0 && grid[vr][vc] != pattern[vj]) || vj == k) {
                vj = lps[vj - 1];
            }
            vj = vj + (grid[vr][vc] == pattern[vj] ? 1 : 0);

            if (vj == k) {
                ++vPresums[i - k + 1];
                --vPresums[i + 1];
            }
        }
        for (int i = 1; i < len; ++i) {
            hPresums[i] += hPresums[i - 1];
            vPresums[i] += vPresums[i - 1];
        }

        int ret = 0;
        for (int i = 0; i < len; ++i) {
            if (hPresums[i] == 0) { continue; }
            int r = i / n, c = i % n;
            if (vPresums[c * m + r] == 0) { continue; }

            ++ret;
        }

        return ret;
    }
};
