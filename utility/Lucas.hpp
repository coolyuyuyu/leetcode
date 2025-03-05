// https://oi-wiki.org/math/number-theory/lucas/

// for prime p:
// C(n, m) % p = C(n / p, m / p) * C(n % p, m % p) % p
long long Lucas(long long n, long long m, long long p) {
    if (m == 0) return 1;
    return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}
