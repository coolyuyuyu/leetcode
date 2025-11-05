class Solution {
public:
    int byDP(string colors, vector<int>& neededTime) {
        int n = colors.size();

        colors.insert(colors.begin(), '#');
        neededTime.insert(neededTime.begin(), 0);

        // dp[i][c]: the minimum needed to make the rope[1:i] colorful and ending color is c.
        int dp[n + 1][27];
        for (int c = 0; c < 26; ++c) {
            dp[0][c] = INT_MAX / 2;
        }
        dp[0][26] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int c = 0; c <= 26; ++c) {
                dp[i][c] = dp[i - 1][c] + neededTime[i]; // delete colors[i]
                if (colors[i] == 'a' + c) { // keep colors[i]
                    for (int d = 0; d <= 26; ++d) {
                        if (d == c) { continue; }
                        dp[i][c] = std::min(dp[i][c], dp[i - 1][d]);
                    }
                }
            }
        }

        int ret = INT_MAX;
        for (int c = 0; c < 26; ++c) {
            ret = std::min(ret, dp[n][c]);
        }

        return ret;
    }

    int byGreedy(string colors, vector<int>& neededTime) {
        int ret = 0;
        for (int i = 0, n = colors.size(); i < n;) {
            int j = i, mx = 0;
            for (; j < n && colors[i] == colors[j]; ++j) {
                ret += neededTime[j];
                mx = std::max(mx, neededTime[j]);
            }
            ret -= mx;

            i = j;
        }

        return ret;
    }

    int minCost(string colors, vector<int>& neededTime) {
        return byDP(colors, neededTime);
        //return byGreedy(colors, neededTime);
    }
};
