class Solution {
public:
    long long distributeCandies(int n, int limit) {
        std::function<long long(int, int)> f = [](int n, int r) {
            if (n < r) { return 0LL; }
            long long ret = 1;
            for (int i = 0; i < r; ++i) {
                ret *= (n - i);
            }
            for (int i = 0; i < r; ++i) {
                ret /= (i + 1);
            }

            return ret;
        };

        long long ret = 0;

        // all possible distribution
        ret += f(n + 2, 2);

        // at least 1 child is distributed more than limit
        ret -= f(3, 1) * f(n - (limit + 1) + 2, 2);

        // at least 2 childs are distributed more than limit
        ret += f(3, 2) * f(n - (limit + 1) * 2 + 2, 2);

        // at least 3 childs are distributed more than limit
        ret -= f(3, 3) * f(n - (limit + 1) * 3 + 2, 2);

        return ret;
    }
};
