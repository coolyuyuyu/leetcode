class Solution {
public:
    long long numberOfPowerfulInt(const string& maxnum, int limit, const string& suffix) {
        if (maxnum.size() < suffix.size()) {
            return 0;
        }

        bool rhtGE = !std::lexicographical_compare(maxnum.end() - suffix.size(), maxnum.end(), suffix.begin(), suffix.end());
        std::function<long long(int, bool)> dfs = [&](int i, bool same) {
            if (i + suffix.size() >= maxnum.size()) {
                return (rhtGE || !same) ? 1LL : 0LL;
            }

            long long ret;
            if (same) {
                ret = 0;
                for (int d = 0; d <= std::min(maxnum[i] - '0', limit); ++d) {
                    ret += dfs(i + 1, d == maxnum[i] - '0');
                }
            }
            else {
                ret = 1;
                for (int exp = maxnum.size() - i - suffix.size(); 0 < exp--;) {
                    ret *= (limit + 1);
                }
            }

            return ret;
        };

        return dfs(0, true);
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return numberOfPowerfulInt(std::to_string(finish), limit, s) - numberOfPowerfulInt(std::to_string(start - 1), limit, s);
    }
};
