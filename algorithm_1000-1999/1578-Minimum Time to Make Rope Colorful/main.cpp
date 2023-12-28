class Solution {
public:
    int byDP(string colors, vector<int>& neededTime) {
        int n = colors.size();

        colors.insert(colors.begin(), '#');
        neededTime.insert(neededTime.begin(), 0);

        // dp[i][j]: minimum time needed to make the colors[1:i] colorful and the remaining ending color is j
        int dp[n + 1][27];
        dp[0][26] = 0;
        for (int j = 1; j <= 26; ++j) {
            dp[0][j] = INT_MAX / 2;
        }
        for (int i = 1; i <= n; ++i) {
            for (int c = 0; c <= 26; ++c) {
                dp[i][c] = INT_MAX / 2;

                dp[i][c] = std::min(dp[i][c], dp[i - 1][c] + neededTime[i]); // delete colors[i]
                if (colors[i] == 'a' + c) { // keep colors[i]
                    for (int d = 0; d <= 26; ++d) {
                        if (c == d) { continue; }
                        dp[i][c] = std::min(dp[i][c], dp[i - 1][d]);
                    }
                }
            }
        }

        int ret = INT_MAX;
        for (char j = 0; j <= 26; ++j) {
            ret = std::min(ret, dp[n][j]);
        }

        return ret;
    }

    int byGreedy(string colors, vector<int>& neededTime) {
        int n = colors.size();

        int ret = 0;
        for (int i = 0; i < n;) {
            int sum = 0, mx = 0;
            int j = i;
            while (j < n && colors[i] == colors[j]) {
                sum += neededTime[j];
                mx = std::max(mx, neededTime[j]);
                ++j;
            }

            ret += sum - mx;

            i = j;
        }

        return ret;
    }

    int minCost(string colors, vector<int>& neededTime) {
        //return byDP(colors, neededTime);
        return byGreedy(colors, neededTime);
    }
};
