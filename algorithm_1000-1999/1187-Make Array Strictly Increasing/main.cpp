class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        std::sort(arr2.begin(), arr2.end());

        int n = arr1.size();
        arr1.insert(arr1.begin(), INT_MIN);

        // dp[i][j]: by j operations to make arr1[1:i] strictly increasing, the minimum value of arr1[i]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        dp[0][0] = INT_MIN;;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = (dp[i - 1][0] < arr1[i] ? arr1[i] : INT_MAX);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = INT_MAX;
                if (j < i && dp[i - 1][j] < arr1[i]) {
                    dp[i][j] = arr1[i];
                }

                auto itr = std::upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1]);
                if (itr != arr2.end()) {
                    dp[i][j] = std::min(dp[i][j], *itr);
                }
            }
        }

        for (int j = 0; j <= n; ++j) {
            if (dp[n][j] < INT_MAX) {
                return j;
            }
        }

        return -1;
    }
};
