class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        books.insert(books.begin(), {0, 0});

        // dp[i]: the minimum height of bookshelf from books[1:i]
        int dp[n + 1];
        std::fill(dp, dp + n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int totalW = 0, maxH = 0;
            for (int j = i; j >= 1; --j) {
                int w = books[j][0], h = books[j][1];
                totalW += w;
                if (totalW > shelfWidth) {
                    break;
                }
                maxH = std::max(maxH, h);
                dp[i] = std::min(dp[i], dp[j - 1] + maxH);
            }
        }

        return dp[n];
    }
};
