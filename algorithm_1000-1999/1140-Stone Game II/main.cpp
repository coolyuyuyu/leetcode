class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suf(n + 1);
        suf[n] = 0;
        std::partial_sum(piles.rbegin(), piles.rend(), suf.rbegin() + 1);

        vector<vector<int>> cache(n, vector<int>(n + 1, 0));
        std::function<int(int, int)> solve = [&](int i, int M) {
            if (piles.size() <= i) {
                return 0;
            }

            int& ret = cache[i][M];
            if (ret != 0) {
                return ret;
            }

            int sum = 0;
            for (int X = 1; X <= (2 * M) && (i + X - 1) < n; ++X) {
                sum += piles[i + X - 1];
                ret = std::max(ret, sum + suf[i + X] - solve(i + X, std::max(M, X)));
            }

            return ret;
        };

        return solve(0, 1);
    }
};
