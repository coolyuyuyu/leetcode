// V1: find all primes where lo <= prime <= hi
vector<int> findPrimes(int lo, int hi) {
    int n = hi;

    vector<int> primes;

    bool isPrimes[n + 1];
    std::fill(isPrimes, isPrimes + n + 1, true);
    isPrimes[0] = false;
    if (1 <= n) {
        isPrimes[1] = false;
    }

    for (int i = 2, limit = sqrt(n); i <= limit; i++) {
        if (!isPrimes[i]) { continue; }

        for (int j = i * 2; j <= n; j += i) {
            isPrimes[j] = false;
        }
    }

    for (int i = lo; i <= hi; ++i) {
        if (isPrimes[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = findPrimes(left, right);
        if (primes.size() < 2) {
            return {-1, -1};
        }

        vector<int> ret = {0, INT_MAX};
        for (int i = 1; i < primes.size(); ++i) {
            if (primes[i] - primes[i - 1] < ret[1] - ret[0]) {
                ret = {primes[i - 1], primes[i]};
            }
        }

        return ret;
    }
};
