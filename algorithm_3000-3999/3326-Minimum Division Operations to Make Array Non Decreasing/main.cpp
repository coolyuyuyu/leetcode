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

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *std::max_element(nums.begin(), nums.end());
        vector<int> primes = findPrimesLT(std::sqrt(maxNum) + 1);

        int ret = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                for (int j = 0; j < primes.size() && primes[j] * primes[j] <= nums[i]; ++j) {
                    if (nums[i] % primes[j] == 0) {
                        nums[i] = primes[j];
                        ++ret;
                        break;
                    }
                }
            }
            if (nums[i] > nums[i + 1]) {
                return -1;
            }
        }

        return ret;
    }
};
