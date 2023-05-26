class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        books.insert(books.begin(), {0, 0});
        vector<int> dp(n + 1, INT_MAX); // dp[i]: the minimum possible height of books[1:i]
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int totalWidth = 0, maxHeight = 0;
            for (int j = i + 1; 1 < j--;) {
                totalWidth += books[j][0];
                maxHeight = std::max(maxHeight, books[j][1]);
                if (shelfWidth < totalWidth) {
                    break;
                }
                dp[i] = std::min(dp[i], dp[j - 1] + maxHeight);
            }
        }

        return dp[n];
    }
};
