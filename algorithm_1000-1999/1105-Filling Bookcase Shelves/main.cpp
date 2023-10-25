class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        books.insert(books.begin(), {0, 0});

        //dp[i]: the minimum height of bookshelf can be after placing books[1:i]
        int dp[n + 1];
        std::fill(dp, dp + n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int width = 0, maxHeight = 0;
            for (int j = i; j >= 1; --j) {
                width += books[j][0];
                if (width > shelfWidth) {
                    break;
                }
                maxHeight = std::max(maxHeight, books[j][1]);
                dp[i] = std::min(dp[i], dp[j - 1] + maxHeight);
            }
        }

        return dp[n];
    }
};
