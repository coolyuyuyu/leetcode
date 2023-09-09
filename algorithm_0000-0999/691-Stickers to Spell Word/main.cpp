class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = (1 << target.size());

        std::function<int(int, const string&)> nextState = [&](int state, const string& word) {
            for (char c : word) {
                for (int i = 0; i < target.size(); ++i) {
                    if (((state >> i) & 1) == 0 && target[i] == c) {
                        state |= (1 << i);
                        break;
                    }
                }
            }

            return state;
        };

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX) { continue; }
            for (const string& word : stickers) {
                int j = nextState(i, word);
                dp[j] = std::min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
    }
};
