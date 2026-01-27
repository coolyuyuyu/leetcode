class Solution {
public:
    long long countDistinct(long long n) {
        string num = std::to_string(n);
        int len = num.size();

        long long ret = 0;
        for (int l = 1; l < len; ++l) {
            ret += std::pow(9, l);
        }

        long long cache[len][2];
        std::fill(&cache[0][0], &cache[0][0] + len * 2, -1);
        std::function<long long(int, bool)> f = [&](int i, bool tight) -> long long {
            if (i >= len) {
                return 1;
            }
            else if (!tight) {
                return std::pow(9, len - i);
            }
            else if (num[i] == '0') {
                return 0;
            }

            if (cache[i][tight] >= 0) {
                return cache[i][tight];
            }

            long long& ret = cache[i][tight] = 0;
            for (char d = '1'; d <= num[i]; ++d) {
                ret += f(i + 1, d == num[i]);
            }

            return ret;
        };
        ret += f(0, true);

        return ret;
    }
};
