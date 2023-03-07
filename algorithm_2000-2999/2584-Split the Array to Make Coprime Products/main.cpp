class Solution {
public:
    vector<int> computePrimes(int n) {
        if (n < 2) {
            return {};
        }

        vector<bool> isPrimes(n + 1, true);
        vector<int> primes = {2};
        for (int i = 3, limit = sqrt(n); i <= limit; i += 2) {
            if (!isPrimes[i]) {
                continue;
            }

            primes.push_back(i);

            for (int j = i * i; j < n; j += i) {
                isPrimes[j] = false;
            }
        }

        return primes;
    }

    map<int, int> factorize(int num, const vector<int>& primes) {
       map<int, int> cnts;
       for (int prime : primes) {
           if (num < (prime * prime)) {
               break;
           }

           while ((num % prime) == 0) {
               num /= prime;
               ++cnts[prime];
           }
       }
       if (1 < num) {
           ++cnts[num];
       }

       return cnts;
    }

    int checkFactorizationCoPrime(const vector<int>& nums) {
        vector<int> primes = computePrimes(*std::max_element(nums.begin(), nums.end()));

        int n = nums.size();

        vector<map<int, int>> cntsOfAll(n);
        for (int i = 0; i < n; ++i) {
            cntsOfAll[i] = factorize(nums[i], primes);
        }

        map<int, int> cntsL, cntsR;
        for (const map<int, int>& cnts : cntsOfAll) {
            for (auto [prime, cnt] : cnts) {
                cntsR[prime] += cnt;
            }
        }

        int common = 0;
        for (int i = 0; (i + 1) < n; ++i) {
            const map<int, int>& cnts = cntsOfAll[i];
            for (auto [prime, cnt] : cnts) {
                if (0 < cntsL[prime] && 0 < cntsR[prime]) {
                    --common;
                }
                cntsL[prime] += cnt;
                cntsR[prime] -= cnt;
                if (0 < cntsL[prime] && 0 < cntsR[prime]) {
                    ++common;
                }
            }

            if (common == 0) {
                return i;
            }
        }

        return -1;
    }

    int byPrimeRangeOverlap(const vector<int>& nums) {
        vector<int> primes = computePrimes(*std::max_element(nums.begin(), nums.end()));

        int n = nums.size();

        unordered_map<int, pair<int, int>> ranges; // prime -> range;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (num == 1) {
                continue;
            }

            for (int prime : primes) {
                if (num < (prime * prime)) {
                    break;
                }

                if ((num % prime) == 0) {
                    if (ranges.find(prime) == ranges.end()) {
                        ranges[prime].first = i;
                    }
                    ranges[prime].second = i;

                    while ((num % prime) == 0) {
                        num /= prime;
                    }
                }
            }
            if (1 < num) {
                if (ranges.find(num) == ranges.end()) {
                    ranges[num].first = i;
                }
                ranges[num].second = i;
            }
        }

        vector<int> diff(n, 0);
        for (const auto& [prime, range] : ranges) {
            ++diff[range.first];
            --diff[range.second];
        }

        int sum = 0;
        for (int i = 0; (i + 1) < diff.size(); ++i) {
            sum += diff[i];
            if (sum == 0) {
                return i;
            }
        }

        return -1;
    }

    int findValidSplit(vector<int>& nums) {
        return checkFactorizationCoPrime(nums);
        //return byPrimeRangeOverlap(nums);
    }
};
