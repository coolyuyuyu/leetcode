class Solution {
public:
    int M = 1e9 + 7;

    int numberOfWays(int numPeople) {
        int cache[numPeople + 1];
        cache[0] = 1;
        for (int i = 1; i <= numPeople; ++i) {
            cache[i] = -1;
        }
        std::function<int(int)> f = [&](int n) {
            int& ret = cache[n];
            if (0 <= ret) {
                return ret;
            }

            ret = 0;
            for (int i = 0; i + 2 <= n; i += 2) {
                ret += (long long)f(i) * f(n - i - 2) % M;
                ret %= M;
            }

            return ret;
        };

        return f(numPeople);
    }
};
