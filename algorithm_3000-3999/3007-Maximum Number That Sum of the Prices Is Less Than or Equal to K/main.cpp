class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        std::function<bool(long long)> checkPriceSumLE = [&](long long num) {
            // num: X X X 0 Y Y Y
            // =>  (0 ~ XXX-1) 1 (2^len(YYY))

            // num: X X X 1 Y Y Y
            // => (0 ~ XXX-1) 1 (2^len(YYY)))
            // => (XXX) 1 (YYY)

            long long sum = 0;
            for (int i = x - 1; (1LL << i) <= num; i += x) {
                long long lftNum = num >> (i + 1);
                int b = (num >> i) & 1;
                long long rhtNum = num & ((1LL << i) - 1);
                if (b == 0) {
                    sum += lftNum * pow(2, i);
                }
                else {
                    sum += lftNum * pow(2, i);
                    sum += rhtNum + 1;
                }

                if (sum > k) {
                    return false;
                }
            }

            return true;
        };

        long long lo = 1, hi = (long long)(1e15) << 8;
        while (lo < hi) {
            long long mid = hi - (hi - lo) / 2;
            if (checkPriceSumLE(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
