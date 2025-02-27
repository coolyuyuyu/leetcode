 class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> num2idx;
        for (int i = 0; i < n; ++i) {
            num2idx[arr[i]] = i;
        }

        int ret = 0;

        // dp[j][i]: the length of the longest Fibonacci-like subsequence where arr[j] and arr[i] are the last 2 elments
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = 2;
                if (arr[i] - arr[j] < arr[j] && num2idx.find(arr[i] - arr[j]) != num2idx.end()) {
                    int k = num2idx[arr[i] - arr[j]];
                    dp[j][i] = dp[k][j] + 1;
                }
                ret = std::max(ret, dp[j][i]);
            }
        }

        return ret <= 2 ? 0 : ret;
    }
};
