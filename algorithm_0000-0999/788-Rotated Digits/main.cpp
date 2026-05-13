class Solution {
public:
    int byBruteForce(int n) {
        bool same = true;
        std::function<bool(int)> checkValid = [](int num) {
            bool different = false;
            for (; num; num /= 10) {
                int d = num % 10;
                switch (d) {
                    case 0:
                    case 1:
                    case 8:
                        break;
                    case 2:
                    case 5:
                    case 6:
                    case 9:
                        different = true;
                        break;
                    default:
                        return false;
                }
            }
            return different;
        };

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            if (checkValid(i)) {
                ++ret;
            }
        }

        return ret;
    }

    int byDigitCount(int n) {
        vector<int> digits;
        for (; n; n /= 10) {
            digits.push_back(n % 10);
        }
        std::reverse(digits.begin(), digits.end());

        std::function<int(int, bool, bool)> dfs = [&](int i, bool tight, bool different) {
            if (i >= digits.size()) {
                return different ? 1 : 0;
            }

            int ret = 0;
            for (int d = 0, limit = (tight ? digits[i] : 9); d <= limit; ++d) {
                switch (d) {
                    case 0:
                    case 1:
                    case 8:
                        ret += dfs(i + 1, tight && d == limit, different);
                        break;
                    case 2:
                    case 5:
                    case 6:
                    case 9:
                        ret += dfs(i + 1, tight && d == limit, true);
                        break;
                    default:
                        break;
                }

            }

            return ret;
        };

        return dfs(0, true, false);
    }

    int rotatedDigits(int n) {
        //return byBruteForce(n);
        return byDigitCount(n);
    }
};
