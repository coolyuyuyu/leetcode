class Solution {
public:
    double recursion(int n) {
        if (5000 < n) {
            return 1.0;
        }
        n = (n + 24) / 25;

        double cache[201][201];
        for (int i = 0; i <= 200; ++i) {
            for (int j = 0; j <= 200; ++j) {
                cache[i][j] = -1.0;
            }
        }
        std::function<double(int, int)> f = [&](int a, int b) {
            if (a <= 0) {
                return (b <= 0) ? 0.5 : 1.0;
            }
            else if (b <= 0) {
                return 0.0;
            }

            double& ret = cache[a][b];
            if (0.0 <= ret) {
                return ret;
            }

            ret = 0.0;
            ret += f(a - 4, b - 0) * 0.25;
            ret += f(a - 3, b - 1) * 0.25;
            ret += f(a - 2, b - 2) * 0.25;
            ret += f(a - 1, b - 3) * 0.25;
            return ret;
        };

        return f(n, n);
    }

    double soupServings(int n) {
        return recursion(n);
    }
};
