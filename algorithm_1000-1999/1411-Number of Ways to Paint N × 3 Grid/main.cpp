class Solution {
public:
    int M = 1e9 + 7;

    int numOfWays(int n) {
        std::function<tuple<int, int, int>(int)> decode = [](int code) -> tuple<int, int, int> {
            return std::make_tuple(code / 9, (code / 3) % 3, code % 3);
        };

        bool oneRow[27];
        for (int code = 0; code < 27; ++code) {
            auto [a, b, c] = decode(code);
            oneRow[code] = (a != b && b != c);
        }
        bool twoRow[27][27];
        for (int code1 = 0; code1 < 27; ++code1) {
            auto [a1, b1, c1] = decode(code1);
            for (int code2 = 0; code2 < 27; ++code2) {
                auto [a2, b2, c2] = decode(code2);
                if (oneRow[code1] == false || oneRow[code2] == false) {
                    twoRow[code1][code2] = false;
                }
                else {
                    twoRow[code1][code2] = (a1 != a2 && b1 != b2 && c1 != c2);
                }
            }
        }

        int dp[27];
        for (int code = 0; code < 27; ++code) {
            dp[code] = oneRow[code] ? 1 : 0;
        }

        for (int i = 1; i < n; ++i) {
            int tmp[27];
            std::copy(dp, dp + 27, tmp);
            for (int cur = 0; cur < 27; ++cur) {
                dp[cur] = 0;
                for (int pre = 0; pre < 27; ++pre) {
                    if (twoRow[cur][pre]) {
                        dp[cur] += tmp[pre];
                        dp[cur] %= M;
                    }
                }
            }
        }

        int ret = 0;
        for (int code = 0; code < 27; ++code) {
            ret += dp[code];
            ret %= M;
        }

        return ret;
    }
};
