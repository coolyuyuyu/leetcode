class Solution {
public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        bool dp[w1 + 1][w2 + 1];
        for (int i = 0; i <= w1; ++i) {
            for (int j = 0; j <= w2; ++j) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;

        int ret = 0;
        for (int w : weights) {
            bool tmp[w1 + 1][w2 + 1];
            for (int i = 0; i <= w1; ++i) {
                for (int j = 0; j <= w2; ++j) {
                    tmp[i][j] = dp[i][j];
                }
            }
            for (int s1 = 0; s1 <= w1; ++s1) {
                for (int s2 = 0; s2 <= w2; ++s2) {
                    if (s1 >= w && tmp[s1 - w][s2]) {
                        dp[s1][s2] = true;
                        ret = std::max(ret, s1 + s2);
                    }

                    if (s2 >= w && tmp[s1][s2 - w]) {
                        dp[s1][s2] = true;
                        ret = std::max(ret, s1 + s2);
                    }
                }
            }
        }

        return ret;
    }
};
