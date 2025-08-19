class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        std::function<long long(long long)> generatePalinO = [](long long num) {
            long long ret = num / 10;
            for (; num; num /= 10) {
                ret = ret * 10 + num % 10;
            }
            return ret;
        };
        std::function<long long(long long)> generatePalinE = [](long long num) {
            long long ret = num;
            for (; num; num /= 10) {
                ret = ret * 10 + num % 10;
            }
            return ret;
        };
        std::function<bool(long long)> checkPalin = [](long long num) {
            string s = std::to_string(num);
            string t = s;
            std::reverse(t.begin(), t.end());
            return s == t;
        };

        // super palin (1e18) => palin (1e9) => half (1e5)

        long long lft = std::stoll(left);
        long long rht = std::stoll(right);

        int ret = 0;
        for (long long half = 0; half < 1e5; ++half) {
            for (long long x : {generatePalinO(half), generatePalinE(half)}) {
                if (x > 1e9) { continue; }
                long long y = x * x;
                if (lft <= y && y <= rht && checkPalin(y)) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
