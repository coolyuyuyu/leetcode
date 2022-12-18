class Solution {
public:
    // slow version
    int slow(int n) {
        if (n < 3) {
            return 0;
        }

        int ret = 0;

        vector<bool> isPrimes(n, true);
        isPrimes[0] = isPrimes[1] = false;
        for (int i = 2; i < n; ++i) {
            if (isPrimes[i]) {
                ++ret;
                for (int num = i*2; num < n; num += i) {
                    isPrimes[num] = false;
                }
            }
        }

        return ret;
    }

    // fast version
    int fast(int n) {
        if (n < 3) {
            return 0;
        }

        int primeCount = n / 2;
        vector<bool> isPrimes(n, true);
        int upperLimit = sqrt(n - 1);
        for (int i = 3; i <= upperLimit; i += 2) {
            if (!isPrimes[i]) {
                continue;
            }

            for (int j = i * i; j < n; j += (2 * i)) {
                if (isPrimes[j]) {
                    --primeCount;
                    isPrimes[j] = false;
                }
            }
        }

        return primeCount;
    }

    int countPrimes(int n) {
        //return slow(n);
        return fast(n);
    }
};
