class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ret = 0;
        if (n > k) {
            ret += 1LL * (n - k) * (k);
        }
        if (m > k) {
            ret += 1LL * (m - k) * (k);
        }

        return ret;
    }
};
