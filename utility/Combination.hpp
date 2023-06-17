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