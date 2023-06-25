class Solution {
public:
    int M = 1e9 + 7;

    int dp1(const vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();

        // dp[f][i]: the count of all possible routes ending at ith city with remaining fuel f
        vector<vector<int>> dp(fuel + 1, vector<int>(n, 0));
        dp[fuel][start] = 1;
        for (int f = fuel; 0 <= f; --f) {
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    if (from == to) {
                        continue;
                    }

                    int cost = std::abs(locations[to] - locations[from]);
                    if (0 <= (f - cost)) {
                        dp[f - cost][to] += dp[f][from];
                        dp[f - cost][to] %= M;
                    }
                }
            }
        }

        int ret = 0;
        for (int f = fuel; 0 <= f; --f) {
            ret += dp[f][finish];
            ret %= M;
        }

        return ret;
    }

    int dp2(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();

        int startLoc = locations[start], finishLoc = locations[finish];
        std::sort(locations.begin(), locations.end());
        for (int i = 0; i < n; ++i) {
            if (locations[i] == startLoc) {
                start = i;
            }
            if (locations[i] == finishLoc) {
                finish = i;
            }
        }

        // dp[f][i][0]: the count of all possible routes stopping at ith city with remaining fuel f
        // dp[f][i][1]: the count of all possible routes moving left and passing ith city with remaining fuel f
        // dp[f][i][2]: the count of all possible routes moving right and passing ith city with remaining fuel f
        vector<vector<vector<int>>> dp(fuel + 1, vector<vector<int>>(n, vector<int>(3, 0)));
        dp[fuel][start][0] = 1;
        for (int f = fuel; 0 <= f; --f) {
            for (int i = 0; i < n; ++i) {
                if (0 < i && 0 <= f - (locations[i] - locations[i - 1])) {
                    int cost = locations[i] - locations[i - 1];
                    dp[f - cost][i][0] += (dp[f][i - 1][0] + dp[f][i - 1][2]) % M;
                    dp[f - cost][i][0] %= M;
                    dp[f - cost][i][2] += (dp[f][i - 1][0] + dp[f][i - 1][2]) % M;
                    dp[f - cost][i][2] %= M;
                }
                if ((i + 1) < n && 0 <= f - (locations[i + 1] - locations[i])) {
                    int cost = locations[i + 1] - locations[i];
                    dp[f - cost][i][0] += (dp[f][i + 1][0] + dp[f][i + 1][1]) % M;
                    dp[f - cost][i][0] %= M;
                    dp[f - cost][i][1] += (dp[f][i + 1][0] + dp[f][i + 1][1]) % M;
                    dp[f - cost][i][1] %= M;
                }
            }
        }

        int ret = 0;
        for (int f = fuel; 0 <= f; --f) {
            ret += dp[f][finish][0];
            ret %= M;
        }

        return ret;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        //return dp1(locations, start, finish, fuel);
        return dp2(locations, start, finish, fuel);
    }
};
