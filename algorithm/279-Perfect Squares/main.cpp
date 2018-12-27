class Solution {
public:

    int numSquaresRecv(int n) {
        static vector<int> cache = {0 , 1};
        if (cache.size() <= n) {
            cache.resize(n + 1, INT_MAX);
        }

        if (cache[n] != INT_MAX) {
            return cache[n];
        }

        for (int base = 1; base * base <= n; ++base) {
            cache[n] = min(cache[n], numSquaresRecv(n - base * base) + 1);
        }

        return cache[n];
    }

    int numSquaresDp(int n) {
        static vector<int> cache = {0 , 1};

        int oldSize = cache.size();
        if (oldSize <= n) {
            cache.resize(n + 1, INT_MAX);
        }

        for (int i = oldSize; i <= n; ++i) {
            for (int base = 1; base * base <= i; ++base) {
                cache[i] = min(cache[i], cache[i - base * base] + 1);
            }
        }

        return cache[n];
    }


    int numSquares(int n) {
        assert(0 < n);

        //return numSquaresRecv(n);

        return numSquaresDp(n);
    }
};