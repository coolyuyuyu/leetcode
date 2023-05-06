class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();

        // dp[i]: the maximum number of books you can take from the subarray ending at ith shelf
        vector<long long> dp(n);
        stack<int> stk;
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && books[stk.top()] > (books[i] - (i - stk.top()))) {
                stk.pop();
            }

            if (stk.empty()) {
                int len = std::min(books[i], i + 1);
                dp[i] = (long long)(books[i] + books[i] - len + 1) * len / 2;
            }
            else {
                int j = stk.top();
                int len = i - j;
                dp[i] = dp[stk.top()] + (long long)(books[i] + books[i] - len + 1) * len / 2;
            }
            ret = std::max(ret, dp[i]);

            stk.push(i);
        }

        return ret;
    }
};
