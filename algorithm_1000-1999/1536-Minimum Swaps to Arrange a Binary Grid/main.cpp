class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        int cnt0s[n]; // number of trailing zero
        for (int r = 0; r < n; ++r) {
            cnt0s[r] = 0;
            for (int c = n - 1; c >= 0; --c) {
                if (grid[r][c] == 1) {
                    break;
                }
                ++cnt0s[r];
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int need0 = n - 1 - i;
            int j = i;
            for (; j < n; ++j) {
                if (cnt0s[j] >= need0) {
                    break;
                }
            }
            if (j == n) { return -1; }

            ret += (j - i);

            int tmp = cnt0s[j];
            for (; j > i; --j) {
                cnt0s[j] = cnt0s[j - 1];
            }
            cnt0s[i] = tmp;
        }

        return ret;
    }
};
