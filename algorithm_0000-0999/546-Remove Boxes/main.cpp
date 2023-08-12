class Solution {
public:
    int dp[105][105][105];
    int removeBoxes(vector<int>& boxes) {
        std::function<int(int, int, int)> dfs = [&](int l, int r, int k) {
            if (l > r) {
                return 0;
            }

            int& ret = dp[l][r][k];
            if (0 < ret) {
                return ret;
            }

            int cnt = k;
            int i = r;
            while (l <= i && boxes[i] == boxes[r]) {
                --i;
                ++cnt;
            }
            ret = dfs(l, i, 0) + cnt * cnt;

            for (int j = i; l <= j; --j) {
                if (boxes[j] != boxes[r]) { continue; }
                if (boxes[j + 1] == boxes[r]) { continue; }

                ret = std::max(ret, dfs(l, j, cnt) + dfs(j + 1, i, 0));
            }

            return ret;
        };

        return dfs(0, boxes.size() - 1, 0);
    }
};

// dp[l][r][k]: maximum points from boxes[l:r] with k boxes of same color as boxes[r] appened at the end
//         ? ... OOO   XXX   OOO   XXX   OOO   [...]
//         ^       ^     ^     ^     ^     ^   ^   ^
//         l       j1    i1    j0    i0    r   --k--

// 1.     |                            |
//     dp[l][i0][0] + (r - i0 + k) ^ 2

// 2.     |                |
//     dp[l][j0][r - i0 + k] + dp[j0 + 1][i0][0]

// 3.     |          |
//     dp[l][j1][r - i0 + k] + dp[j1 + 1][i0][0]
