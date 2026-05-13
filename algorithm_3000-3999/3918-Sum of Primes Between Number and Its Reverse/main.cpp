class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int r = 0; {
            for (int num = n; num; num /= 10) {
                r = r * 10 + num % 10;
            }
        }
        int lo = std::min(n, r), hi = std::max(n, r);

        std::function<bool(int)> checkPrime = [](int num) {
            if (num <= 1) { return false; }
            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    return false;
                }
            }

            return true;
        };

        int ret = 0;
        for (int num = lo; num <= hi; ++num) {
            if (checkPrime(num)) {
                ret += num;
            }
        }

        return ret;
    }
};
