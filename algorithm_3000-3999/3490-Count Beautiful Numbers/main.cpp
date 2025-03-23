class Solution {
public:
    int beautifulNumbers(int l, int r) {
        std::function<int(int)> countBeautifulNumbers = [&](int n) {
            vector<int> digits;
            for (; n; n /= 10) {
                digits.push_back(n % 10);
            }
            std::reverse(digits.begin(), digits.end());

            map<tuple<int, int, int, bool, bool>, int> cache;
            std::function<int(int, int, int, bool, bool)> f = [&](int i, int sum, int prod, bool leadingZero, bool closeLimit) {
                if (i >= digits.size()) {
                    return (sum > 0 && prod % sum == 0) ? 1 : 0;
                }

                auto key = std::make_tuple(i, sum, prod, leadingZero, closeLimit);
                if (cache.find(key) != cache.end()) {
                    return cache[key];
                }

                int& ret = cache[key] = 0;
                for (int d = 0, limit = (closeLimit ? digits[i] : 9); d <= limit; ++d) {
                    ret += f(i + 1, sum + d, (leadingZero && d == 0) ? 1 : (prod * d), leadingZero && d == 0, closeLimit && d == limit);
                }

                return ret;

            };
            return f(0, 0, 1, true, true);
        };

        return countBeautifulNumbers(r) - countBeautifulNumbers(l - 1);
    }
};
