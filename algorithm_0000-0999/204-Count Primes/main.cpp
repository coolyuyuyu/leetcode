class Solution {
public:
    // slow version
    int f1(int n) {
        if (n < 3) {
            return 0;
        }

        int ret = 0;

        vector<bool> isPrimes(n, true);
        for (int i = 2; i < n; ++i) {
            if (isPrimes[i]) {
                ++ret;
                for (int num = i * 2; num < n; num += i) {
                    isPrimes[num] = false;
                }
            }
        }

        return ret;
    }

    // fast version
    int f2(int n) {
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
        //return f1(n);
        return f2(n);
    }
};