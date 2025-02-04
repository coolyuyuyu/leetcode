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
