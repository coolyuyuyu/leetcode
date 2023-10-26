class Solution {
public:
    int M = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        unordered_map<int, int> indexes;

        long long dp[n];
        std::fill(dp, dp + n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if ((arr[i] % arr[j]) == 0 && indexes.find(arr[i] / arr[j]) != indexes.end()) {
                    int k = indexes[arr[i] / arr[j]];
                    dp[i] += (dp[j] * dp[k]) % M;
                    dp[i] %= M;
                }
            }

            indexes[arr[i]] = i;
        }

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += dp[i];
            ret %= M;
        }

        return ret;
    }
};
