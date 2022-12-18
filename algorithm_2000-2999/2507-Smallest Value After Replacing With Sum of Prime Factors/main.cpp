class Solution {
public:
    vector<bool> getPrimes(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;

        for (int i = 2; i < (n + 1); ++i) {
            if (!primes[i]) {
                continue;
            }

            for (long long j = (long long)i * i; j < (n + 1); j += i) {
                primes[j] = false;
            }
        }

        return primes;
    }

    int smallestValue(int n) {
        vector<bool> isPrimes = getPrimes(n);
        for (int pre = n + 1; !isPrimes[n] && n < pre;) {
            pre = n;

            int tmp = 0;
            for (int i = 1; i <= n; ++i) {
                if (!isPrimes[i]) {
                    continue;
                }
                while (n % i == 0) {
                    n /= i;
                    tmp += i;
                }
            }
            n = tmp;
        }

        return n;
    }
};
