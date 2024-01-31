class Solution {
public:
    vector<int> findPrinesLT(int n) {
        vector<int> primes;

        bool isPrimes[n];
        std::fill(isPrimes, isPrimes + n, true);

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

    bool checkVowel(char c) {
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
    }

    long long beautifulSubstrings(string s, int k) {
        // X X X X X j [X X X i]
        // assume s[j+1:i] meets requirements
        // => ((i-j)/2)^2 % k == 0
        // => (i-j)^2 / 4 % k == 0
        // => (i-j)^2 % 4k == 0
        // => (i-j) % sqrt(4k)
        // => i % sqrt(4k) == j % sqrt(4k)
        // => i % 2*sqrt(k) == j % 2*sqrt(k)

        // define a module x to replace 2*sqrt(k)
        int x = 2;
        for (int prime : findPrinesLT(k + 1)) {
            int cnt = 0;
            while ((k % prime) == 0) {
                k /= prime;
                ++cnt;
            }
            if (cnt == 0) { continue; }

            x *= std::pow(prime, (cnt + (cnt & 1 ? 1 : 0)) / 2);
        }

        // <cnt of vowel - cnt of consonant, i % x> => number of j
        map<pair<int, int>, int> m;
        m[{0, -1 + x}] = 1;

        long long ret = 0;
        for (int i = 0, diff = 0; i < s.size(); ++i) {
            diff += (checkVowel(s[i]) ? 1 : -1);

            ret += m[{diff, i % x}];
            m[{diff, i % x}] += 1;
        }

        return ret;
    }
};
