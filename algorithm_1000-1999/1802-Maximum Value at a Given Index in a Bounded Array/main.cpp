class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        std::function<long(int, int)> sumOneSide = [](int len, int maxNum) {
            int numOnes = std::max(len - maxNum, 0);
            len -= numOnes;
            return 1L * (maxNum - len + 1 + maxNum) * len / 2 + numOnes;
        };
        std::function<bool(int)> canConstruct = [&](int target) {
            long sum = sumOneSide(index + 1, target) + sumOneSide(n - index, target) - target;
            return sum <= maxSum;
        };

        int lo = 1, hi = maxSum;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (canConstruct(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
