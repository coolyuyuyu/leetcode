class Solution {
public:
    // slow version
    /*
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        
        vector<bool> isPrimes(n, true);
        isPrimes[0] = isPrimes[1] = false;
        
        int upperLimit = sqrt(n-1);
        for (int i = 2; i <= upperLimit; ++i) {
            if (isPrimes[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrimes[j] = false;
                }
            }
        }
        
        return count(isPrimes.begin(), isPrimes.end(), true);
    }
    */
    
    // fast version
    int countPrimes(int n) {
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
};