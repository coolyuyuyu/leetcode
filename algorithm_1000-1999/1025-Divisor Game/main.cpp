class Solution {
public:
    // TLE
    bool recursiveDP(size_t n) {
        if (n <= 1) {
            return false;
        }
        else {
            for (size_t i = 1; i < n; ++i) {
                if (n % i == 0 && !recursiveDP(n - i)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool recursiveDP_memorization(size_t n) {
        enum class state {
            kNone,
            kWin,
            kLose,
        };
        static vector<state> cache = {state::kLose, state::kLose};

        if (cache.size() <= n) {
            cache.resize(n + 1, state::kNone);
        }
        if (cache[n] != state::kNone) {
            return cache[n] == state::kWin;
        }

        cache[n] = state::kLose;
        for (size_t i = 1; i <= (n / 2); ++i) {
            if (n % i == 0 && !recursiveDP_memorization(n - i)) {
                cache[n] = state::kWin;
                break;
            }
        }

        return cache[n] == state::kWin;
    }

    bool iterative_memorization(size_t n) {
        static vector<bool> cache = {false, false};

        if (n < cache.size()) {
            return cache[n];
        }

        size_t start = cache.size();
        cache.resize(n + 1);
        for (size_t i = start; i <= n; ++i) {
            for (size_t j = 1; j <= (i / 2); ++j) {
                if (i % j == 0 && !cache[i - j]) {
                    cache[i] = true;
                    break;
                }
            }
        }

        return cache[n];
    }

    bool divisorGame(int n) {
        //return recursiveDP(n);
        //return recursiveDP_memorization(n);
        return iterative_memorization(n);
    }
};