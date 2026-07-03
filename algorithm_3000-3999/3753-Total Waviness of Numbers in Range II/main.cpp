class Solution {
public:
    long long totalWaviness(long long num) {
        string s = std::to_string(num);
        vector<int> digits;
        for (char c : std::to_string(num)) {
            digits.push_back(c - '0');
        }
        int n = digits.size();

        pair<long long, long long> cache[n][11][11][2][2];
        std::fill(&cache[0][0][0][0][0], &cache[0][0][0][0][0] + n * 11 * 11 * 2 * 2, pair<long long, long long>{-1LL, -1LL});
        std::function<pair<long long, long long>(int, int, int, bool, bool)> dfs = [&](int pos, int pre1, int pre2, bool tight, bool started) -> pair<long long, long long> {
            if (pos == n) {
                return {0LL, started ? 1LL : 0LL};
            }

            if (cache[pos][pre1 + 1][pre2 + 1][tight][started].first >= 0) {
                return cache[pos][pre1 + 1][pre2 + 1][tight][started];
            }

            auto& [wav, cnt] = cache[pos][pre1 + 1][pre2 + 1][tight][started] = {0, 0};
            for (int cur = 0, hi = (tight ? digits[pos] : 9); cur <= hi; ++ cur) {
                bool newTight = tight && cur == digits[pos];
                bool newStarted = started || cur > 0;
                int newPre1, newPre2;
                if (!newStarted) {
                    newPre1 = -1, newPre2 = -1;
                }
                else if (!started) {
                    newPre1 = cur, newPre2 = -1;
                }
                else {
                    newPre1 = cur, newPre2 = pre1;
                }

                auto [subwav, subcnt] = dfs(pos + 1, newPre1, newPre2, newTight, newStarted);
                wav += subwav;
                cnt += subcnt;
                if (pre1 >= 0 && pre2 >= 0) {
                    if ((pre2 < pre1 && pre1 > cur) || (pre2 > pre1 && pre1 < cur)) {
                        wav += subcnt;
                    }
                }
            }

            return {wav, cnt};
        };

        auto [ret, _] = dfs(0, -1, -1, true, false);
        return ret;
    }

    long long totalWaviness(long long num1, long long num2) {
        return totalWaviness(num2) - totalWaviness(num1 - 1);
    }
};
