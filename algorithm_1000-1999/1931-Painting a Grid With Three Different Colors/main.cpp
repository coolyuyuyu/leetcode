class Solution {
public:
    int M = 1e9 + 7;

    int colorTheGrid(int m, int n) {
        vector<int> states;
        for (int state = 0; state < pow(3, m); ++state) {
            bool same = false;
            for (int i = 0, s = state, color = -1; i < m && !same; ++i, s /= 3) {
                if ((s % 3) == color) {
                    same = true;
                }
                color = s % 3;
            }
            if (!same) {
                states.push_back(state);
            }
        }

        std::function<bool(int, int)> checkConflict = [&](int s1, int s2) {
            for (int i = 0; i < m; ++i, s1 /= 3, s2 /= 3) {
                if ((s1 % 3) == (s2 % 3)) {
                    return true;
                }
            }
            return false;
        };

        int dp[n][(int)std::pow(3, m)];
        for (int s : states) {
            dp[0][s] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int s1 : states) {
                dp[i][s1] = 0;
                for (int s2 : states) {
                    if (checkConflict(s1, s2)) { continue; }
                    dp[i][s1] += dp[i - 1][s2];
                    dp[i][s1] %= M;
                }
            }
        }

        int ret = 0;
        for (int s : states) {
            ret += dp[n - 1][s];
            ret %= M;
        }

        return ret;
    }
};
