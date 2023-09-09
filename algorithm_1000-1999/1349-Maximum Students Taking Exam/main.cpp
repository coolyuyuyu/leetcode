class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats.empty() ? 0 : seats[0].size();
        seats.insert(seats.begin(), vector<char>(n, '#'));

        // state: binary representation of the student placement in one row
        // dp[r][state]: the maximum number of students placed from the first r row and the state is the student placement at row r
        int dp[m + 1][1 << n];
        for (int state = 0; state < (1 << n); ++state) {
            dp[0][state] = 0;
        }
        std::function<bool(int, int)> checkPlacement = [&](int r, int state) {
            for (int c = 0; c < n; ++c) {
                if ((state >> c) & 1) {
                    if (seats[r][c] == '#') {
                        return false;
                    }
                    if ((c + 1) < n && ((state >> (c + 1)) & 1)) {
                        return false;
                    }
                }
            }

            return true;
        };
        std::function<bool(int, int)> checkFairness = [&](int curState, int preState) {
            for (int c = 0; c < n; ++c) {
                if ((curState >> c) & 1) {
                    if (0 <= (c - 1) && ((preState >> (c - 1)) & 1)) {
                        return false;
                    }
                    if ((c + 1) < n && ((preState >> (c + 1)) & 1)) {
                        return false;
                    }
                }
            }

            return true;
        };
        for (int r = 1; r <= m; ++r) {
            for (int curState = 0; curState < (1 << n); ++curState) {
                dp[r][curState] = 0;
                if (!checkPlacement(r, curState)) { continue; };
                for (int preState = 0; preState < (1 << n); ++preState) {
                    if (!checkPlacement(r - 1, preState)) { continue; };
                    if (checkFairness(curState, preState)) {
                        dp[r][curState] = std::max(dp[r][curState], dp[r - 1][preState] + __builtin_popcount(curState));
                    }
                }
            }
        }

        int ret = 0;
        for (int state = 0; state < (1 << n); ++state) {
            ret = std::max(ret, dp[m][state]);
        }

        return ret;
    }
};
