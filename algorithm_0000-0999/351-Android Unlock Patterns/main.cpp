class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int skip[10][10];
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                skip[i][j] = 0;
            }
        }
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[1][9] = skip[9][1] = 5;
        skip[2][8] = skip[8][2] = 5;
        skip[3][7] = skip[7][3] = 5;
        skip[3][9] = skip[9][3] = 6;
        skip[4][6] = skip[6][4] = 5;
        skip[7][9] = skip[9][7] = 8;

        int ret = 0;
        std::function<void(int,int, int)> dfs = [&](int cur, int state, int cnt) {
            if (cnt > n) {
                return;
            }
            if (cnt >= m) {
                ++ret;
            }

            for (int nxt = 1; nxt <= 9; ++nxt) {
                if (state & (1 << nxt)) { continue; }
                int s = skip[cur][nxt];
                if ((state & (1 << s)) == 0) {continue; }
                dfs(nxt, state | (1 << nxt), cnt + 1);
            }

        };
        dfs(0, 1, 0);

        return ret;
    }
};
