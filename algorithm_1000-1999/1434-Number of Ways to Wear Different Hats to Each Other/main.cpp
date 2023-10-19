class Solution {
public:
    int M = 1e9 + 7;

    int numberWays(vector<vector<int>>& hats) {
        int n = (1 << hats.size());

        unordered_map<int, vector<int>> hat2people;
        for (int i = 0; i < hats.size(); ++i) {
            for (int hat : hats[i]) {
                hat2people[hat].push_back(i);
            }
        }

        // state: the binary representation whether ith person has taken a hat
        // dp[state]: the number of ways to cover this state
        int dp[n];
        std::fill(dp, dp + n, 0);
        dp[0] = 1;

        for (int hat = 1; hat <= 40; ++hat) {
            int tmp[n];
            std::copy(dp, dp + n, tmp);
            for (int person : hat2people[hat]) {
                for (int state = 0; state < n; ++state) {
                    if (state & (1 << person)) { continue; }

                    int nxtState = state | (1 << person);
                    dp[nxtState] += tmp[state];
                    dp[nxtState] %= M;
                }
            }
        }

        return dp[n - 1];
    }
};
