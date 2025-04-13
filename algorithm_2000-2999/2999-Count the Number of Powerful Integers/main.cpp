class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        std::function<long long(string)> cntLE = [&](string num) {
            if (num.size() < s.size()) {
                return 0LL;
            }

            std::function<long long(int, bool)> f = [&](int pos, bool samePrefix) {
                if (pos + s.size() >= num.size()) {
                    return (!samePrefix || num.substr(num.size() - s.size()) >= s) ? 1LL : 0LL;;
                }

                long long ret = 0;
                if (samePrefix) {
                    for (int d = 0; d <= (std::min(limit, (num[pos] - '0'))); ++d) {
                        ret += f(pos + 1, d == (num[pos] - '0'));
                    }
                }
                else {
                    ret = 1;
                    for (int i = pos; i + s.size() < num.size(); ++i) {
                        ret *= (limit + 1);
                    }
                }

                return ret;
            };

            return f(0, true);
        };

        return cntLE(std::to_string(finish)) - cntLE(std::to_string(start - 1));
    }
};
