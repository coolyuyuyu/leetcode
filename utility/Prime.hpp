// find all primes where prime < n
vector<int> findPrimesLT(int n) {
    vector<int> primes;

    bool isPrimes[n];
    std::fill(isPrimes, isPrimes + n, true);
    isPrimes[0] = false;
    if (1 < n) {
        isPrimes[1] = false;
    }

    for (int i = 2, limit = ceil(sqrt(n)); i < n; ++i) {
        if (isPrimes[i]) {
            primes.push_back(i);
        }
        else {
            continue;
        }

        if (i < limit) {
            for (int j = i * i; j < n; j += i) {
                isPrimes[j] = false;
            }
        }
    }

    return primes;
}

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

// V2: find all primes where lo <= prime <= hi
vector<int> findPrimes(int lo, int hi) {
    int n = hi;

    vector<int> primes;

    bool isPrimes[n + 1];
    std::fill(isPrimes, isPrimes + n + 1, true);
    isPrimes[0] = false;
    if (1 <= n) {
        isPrimes[1] = false;
    }

    for (int i = 2, limit = ceil(sqrt(n)); i <= n; ++i) {
        if (!isPrimes[i]) { continue; }

        if (i >= lo) {
            primes.push_back(i);
        }

        if (i <= limit) {
            for (int j = i * i; j <= n; j += i) {
                isPrimes[j] = false;
            }
        }
    }

    return primes;
}
