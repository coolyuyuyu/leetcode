class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // n = (x) + (x+1) + (x+2) + ... + (x+m-1)
        // n = (x + x+m-1) * m / 2
        // 2n/m = (2x + m - 1)
        // x = (2n/m - m + 1) / 2
        // x = (2n - m^2 + m) / 2m

        int ret = 0;
        for (int m = 1, limit = sqrt(2 * n); m <= limit; ++m) {
            int t = 2*n - m*m + m;
            if (t > 0 && t % (2*m) == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
