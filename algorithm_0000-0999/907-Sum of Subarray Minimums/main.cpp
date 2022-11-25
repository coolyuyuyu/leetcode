class Solution {
public:
    // Time: O(n^2), TLE
    int dp(vector<int>& arr) {
        size_t n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n));
        dp[0] = arr;

        int ans = 0;
        for (size_t len = 1; len <= n; ++len) {
            for (size_t i = 0; (i + len) <= n; ++i) {
                dp[len][i] = std::min(dp[len - 1][i], arr[i + len - 1]);
                ans = (ans + dp[len][i]) % 1000000007;
            }
        }

        return ans;
    }

    // Time: O(n)
    int boundary(vector<int>& arr) {
        size_t n = arr.size();

        vector<size_t> lft(n), rht(n, n); // store the index of lft/rht less element
        stack<size_t> stk;
        for (size_t i = 0; i < arr.size(); ++i) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                size_t j = stk.top();
                rht[j] = i;

                stk.pop();
            }
            lft[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int ans = 0;
        for (size_t i = 0; i < n; ++i) {
            size_t lftLen = lft[i] != n ? (i - lft[i]) : i + 1;
            size_t rhtLen = rht[i] != n ? (rht[i] - i) : n - i;
            ans = (ans + arr[i] * lftLen * rhtLen) % 1000000007;
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        //return dp(arr);
        return boundary(arr);
    }
};
