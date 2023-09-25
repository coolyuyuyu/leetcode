class Solution {
public:
    int M = 1e9 + 7;

    int topdn(int numPeople) {
        int cache[numPeople + 1];
        cache[0] = 1;
        for (int i = 2; i <= numPeople; i += 2) {
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

    int btmup(int numPeople) {
        // dp[i]: the number of ways these handshakes could occur for i people
        int dp[numPeople + 1];
        dp[0] = 1;

        for (int i = 2; i <= numPeople; i += 2) {
            dp[i] = 0;
            for (int j = 0; j + 2 <= i; j += 2) {
                dp[i] += ((long long)dp[j] * dp[i - j - 2]) % M;
                dp[i] %= M;
            }
        }

        return dp[numPeople];
    }

    int numberOfWays(int numPeople) {
        return topdn(numPeople);
        //return btmup(numPeople);
    }
};
