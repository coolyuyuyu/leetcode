class Solution {
public:
    vector<int> findPrimesLT(int n) {
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

    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = findPrimesLT(1000 + 1);

        int n = nums.size();
        nums.insert(nums.begin(), 0);

        for (int i = 1; i <= n; ++i) {
            auto itr = std::lower_bound(primes.begin(), primes.end(), nums[i] - nums[i - 1]);
            if (itr != primes.begin()) {
                nums[i] -= *std::prev(itr);
            }
            if (nums[i - 1] >= nums[i]) {
                return false;
            }
        }

        return true;
    }
};
