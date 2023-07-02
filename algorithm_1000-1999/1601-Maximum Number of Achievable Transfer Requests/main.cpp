class Solution {
public:
    int linerarScan(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        std::function<bool(int)> check = [&](int state) {
            vector<int> cnts(n, 0);
            for (int i = 0; state; state >>= 1, ++i) {
                if (state & 1) {
                    cnts[requests[i][0]] -= 1;
                    cnts[requests[i][1]] += 1;
                }
            }

            return std::all_of(cnts.begin(), cnts.end(), [](int cnt) { return cnt == 0; });
        };

        int ret = 0;
        for (int state = 1; state < (1 << m); ++state) {
            if (check(state)) {
                ret = std::max(ret, __builtin_popcount(state));
            }
        }

        return ret;
    }

    int scanTopDnByNextPermutation(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        std::function<bool(int)> check = [&](int state) {
            vector<int> cnts(n, 0);
            for (int i = 0; state; state >>= 1, ++i) {
                if (state & 1) {
                    cnts[requests[i][0]] -= 1;
                    cnts[requests[i][1]] += 1;
                }
            }

            return std::all_of(cnts.begin(), cnts.end(), [](int cnt) { return cnt == 0; });
        };

        for (int ret = m; 0 < ret; --ret) {
            vector<int> perm(m);
            std::fill(perm.begin(), perm.begin() + m - ret, 0);
            std::fill(perm.begin() + m - ret, perm.end(), 1);

            do {
                int state = 0;
                for (int i = 0; i < m; ++i) {
                    if (perm[i] == 1) {
                        state |= (1 << i);
                    }
                }

                if (check(state)) {
                    return ret;
                }
            } while (std::next_permutation(perm.begin(), perm.end()));
        }

        return 0;
    }

    int scanTopDnByGosperHack(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        std::function<bool(int)> check = [&](int state) {
            vector<int> cnts(n, 0);
            for (int i = 0; state; state >>= 1, ++i) {
                if (state & 1) {
                    cnts[requests[i][0]] -= 1;
                    cnts[requests[i][1]] += 1;
                }
            }

            return std::all_of(cnts.begin(), cnts.end(), [](int cnt) { return cnt == 0; });
        };

        for (int ret = m; 0 < ret; --ret) {
            int state = (1 << ret) - 1;
            while (state < (1 << m)) {
                if (check(state)) {
                    return ret;
                }

                int c = state & -state;
                int r = state + c;
                state = (((r ^ state) >> 2) / c) | r;
            }
        }

        return 0;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        //return linerarScan(n, requests);
        //return scanTopDnByNextPermutation(n, requests);
        return scanTopDnByGosperHack(n, requests);
    }
};
