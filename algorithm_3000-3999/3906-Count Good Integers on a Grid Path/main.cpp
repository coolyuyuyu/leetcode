class Solution {
public:
    long long countGoodIntegersOnPath(int num[16], bool onPath[16]) {
        long long cache[16][10][2];
        std::fill(&cache[0][0][0], &cache[0][0][0] + 16 * 10 * 2, -1);
        std::function<long long(int, int, bool)> dfs = [&](int i, int preD, bool tight) {
            if (i >= 16) {
                return 1LL;
            }

            if (cache[i][preD][tight] >= 0) {
                return cache[i][preD][tight];
            }

            long long& ret = cache[i][preD][tight] = 0;
            for (int curD = 0, limit = tight ? num[i] : 9; curD <= limit; ++curD) {
                bool nxtTight = tight && curD == limit;
                if (onPath[i]) {
                    if (preD > curD) { continue; }
                    ret += dfs(i + 1, curD, nxtTight);
                }
                else {
                    ret += dfs(i + 1, preD, nxtTight);
                }
            }

            return ret;
        };

        return dfs(0, 0, true);
    }

    long long countGoodIntegersOnPath(long long n, bool onPath[16]) {
        int num[16];
        std::fill(num, num + 16, 0);

        for (int i = 16 - 1; i >= 0 && n; --i, n /= 10) {
            num[i] = n % 10;
        }

        return countGoodIntegersOnPath(num, onPath);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        bool onPath[16];
        std::fill(onPath, onPath + 16, false);

        int i = 0;
        onPath[i] = true;
        for (char dir : directions) {
            if (dir == 'D') {
                i += 4;
            }
            else {
                i += 1;
            }
            onPath[i] = true;
        }

        return countGoodIntegersOnPath(r, onPath) - countGoodIntegersOnPath(l - 1, onPath);
    }
};
