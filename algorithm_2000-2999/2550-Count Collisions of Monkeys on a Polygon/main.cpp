class Solution {
public:
    long long M = 1e9 + 7;

    long long dp(int n, unordered_map<int, long long>& cache) {
        if (n == 1) {
            return 2;
        }
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }

        long long a = dp(n / 2, cache);
        long long b = dp(n % 2 == 1 ? (n / 2 + 1) : (n / 2), cache);
        return cache[n] = (a * b) % M;
    }

    int monkeyMove(int n) {
        unordered_map<int, long long> cache;
        long long result = dp(n, cache) - 2;
        return (result + M) % M;
    }
};
