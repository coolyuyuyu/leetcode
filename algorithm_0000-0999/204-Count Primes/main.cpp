class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }

        vector<int> isPrimes(n, true);

        int count = 0;
        for (int i = 2, limit = ceil(sqrt(n)); i < n; ++i) {
            if (!isPrimes[i]) {
                continue;
            }
            ++count;

            if (i < limit) {
                for (int j = i * i; j < n; j += i) {
                    isPrimes[j] = false;
                }
            }
        }

        return count;
    }
};
