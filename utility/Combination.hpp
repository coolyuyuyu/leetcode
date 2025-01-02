int cache[nums.size()][nums.size()];
std::memset(cache, -1, sizeof(cache));

int comb(int n, int r) {
    if ((n - r) < r) {
        r = n - r;
    }

    if (r == 0) {
        return 1;
    }
    else if (r == 1) {
        return n;
    }

    int& ret = cache[n][r];
    if (ret < 0) {
        // C(m, n) = C(m-1, n) + C(m-1, n-1)
        ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % M;
    }

    return ret;
};

int M = 1e9 + 7;
vector<int> factorial(n);
factorial[0] = 1;
for (int i = 1; i < n; ++i) {
    factorial[i] = 1L * factorial[i - 1] * i % M;
}

std::function<int(int, int)> quickPow = [&](int base, int exp) {
    int ret = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) {
            ret = 1L * ret * base % M;
        }
        base = 1L * base * base % M;
    }

    return ret;
};

std::function<int(int, int)> comb = [&](int m, int n) {
    if (m < n) { return 0; }
    int a = factorial[m];
    int b = 1L * factorial[n] * factorial[m - n] % M;
    int invB = quickPow(b, M - 2);

    return 1L * a * invB % M;
};

