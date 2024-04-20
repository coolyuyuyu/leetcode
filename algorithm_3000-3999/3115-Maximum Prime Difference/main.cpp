class Solution {
public:
    vector<bool> findPrimesLT(int n) {
        vector<bool> isPrimes(n, true);
        isPrimes[0] = isPrimes[1] = false;
        for (int i = 2, limit = ceil(sqrt(n)); i < n; ++i) {
            if (!isPrimes[i]) {
                continue;
            }

            if (i < limit) {
                for (int j = i * i; j < n; j += i) {
                    isPrimes[j] = false;
                }
            }
        }

        return isPrimes;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> isPrimes = findPrimesLT(101);

        int mn = -1, mx;
        for (int i = 0; i < nums.size(); ++i) {
            if (isPrimes[nums[i]]) {
                if (mn == -1) {
                    mn = i;
                }
                mx = i;
            }
        }

        return mx - mn;
    }
};
