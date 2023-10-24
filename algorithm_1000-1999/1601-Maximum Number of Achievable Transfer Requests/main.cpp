class Solution {
public:
    int scan(int n, vector<vector<int>>& requests) {
        int m = requests.size();

        std::function<bool(int)> check = [&](int state) {
            int cnts[n];
            std::fill(cnts, cnts + n, 0);
            for (int i = 0; state; state >>= 1, ++i) {
                if (state & 1) {
                    --cnts[requests[i][0]];
                    ++cnts[requests[i][1]];
                }
            }
            return std::count(cnts, cnts + n, 0) == n;
        };

        int ret = 0;
        for (int state = 0, limit = 1 << m; state < limit; ++state) {
            if (check(state)) {
                ret = std::max(ret, __builtin_popcount(state));
            }
        }

        return ret;
    }

    int scanDecreasinglyByNextPerm(int n, vector<vector<int>>& requests) {
        int m = requests.size();

        std::function<bool(int)> check = [&](int state) {
            int cnts[n];
            std::fill(cnts, cnts + n, 0);
            for (int i = 0; state; state >>= 1, ++i) {
                if (state & 1) {
                    --cnts[requests[i][0]];
                    ++cnts[requests[i][1]];
                }
            }
            return std::count(cnts, cnts + n, 0) == n;
        };

        for (int ret = m; ret >= 1; --ret) {
            bool flag[m];
            std::fill(flag, flag + m - ret, false);
            std::fill(flag + m - ret, flag + m, true);
            do {
                int state = 0;
                for (int i = 0; i < m; ++i) {
                    if (flag[i]) {
                        state |= (1 << i);
                    }
                }

                if (check(state)) {
                    return ret;
                }
            } while (std::next_permutation(flag, flag + m));
        }

        return 0;
    }

    int scanDecreasinglyByGopherHack(int n, vector<vector<int>>& requests) {
        int m = requests.size();

        std::function<bool(int)> check = [&](int state) {
            int cnts[n];
            std::fill(cnts, cnts + n, 0);
            for (int i = 0; state; state >>= 1, ++i) {
                if (state & 1) {
                    --cnts[requests[i][0]];
                    ++cnts[requests[i][1]];
                }
            }
            return std::count(cnts, cnts + n, 0) == n;
        };

        for (int ret = m; ret >= 1; --ret) {
            // Gosper's hack: iterate all the m-bit state where there are k 1-bits.
            int state = (1 << ret) - 1;
            while (state < (1 << m)) {
                if (check(state)) {
                    return ret;
                }

                int c = state & - state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        return 0;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        //return scan(n, requests);
        //return scanDecreasinglyByNextPerm(n, requests);
        return scanDecreasinglyByGopherHack(n, requests);
    }
};
