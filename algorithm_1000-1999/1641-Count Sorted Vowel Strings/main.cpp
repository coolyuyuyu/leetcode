class Solution {
public:
    int byRecursion(int n) {
        int cache[n + 1][5 + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 5; ++j) {
                cache[i][j] = -1;
            }
        }
        std::function<int(int, int)> f = [&](int n, int k) {
            if (n == 1) {
                return k;
            }

            int& ret = cache[n][k];
            if (ret >= 0) {
                return ret;
            }

            ret = 0;
            for (int j = 1; j <= k; ++j) {
                ret += f(n - 1, j);
            }

            return ret;
        };
        return f(n, 5);
    }

    int countVowelStrings(int n) {
        return byRecursion(n);
    }
};
