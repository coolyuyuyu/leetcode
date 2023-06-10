class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        std::function<long(long, long)> sumOneSide = [](long len, long lastNum) {
            long numOne = std::max(len - lastNum, 0L);
            if (len > lastNum) {
                len = lastNum;
            }

            return (lastNum + (lastNum - len + 1)) * len / 2 + numOne;
        };

        std::function<long(int)> sumArr = [&n, &index, &maxSum, &sumOneSide](int target) {
            return sumOneSide(index + 1, target) + sumOneSide(n - index, target) - target;
        };

        int lo = 1, hi = maxSum;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (sumArr(mid) <= maxSum) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
