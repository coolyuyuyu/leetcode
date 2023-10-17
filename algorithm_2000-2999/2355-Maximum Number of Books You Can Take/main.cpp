class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();

        // the maximum number of books you can take from the subarray ending at ith bookshelf
        long long dp[n];

        long long ret = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && books[stk.top()] >= books[i] - (i - stk.top())) {
                stk.pop();
            }
            if (stk.empty()) {
                long long len = std::min(i + 1, books[i]);
                dp[i] = (books[i] + books[i] - len + 1) * len / 2;
            }
            else {
                int j = stk.top();
                long long len = i - j;
                dp[i] = dp[j] + (books[i] + books[i] - len + 1) * len / 2;
            }
            stk.push(i);

            ret = std::max(ret, dp[i]);
        }

        return ret;
    }
};
