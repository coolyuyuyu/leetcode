class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int holdN = 0, holdY = INT_MIN / 2;
        for (int i = 0; i < n; ++i) {
            int tmpN = holdN, tmpY = holdY;
            holdN = std::max(holdN, holdY + prices[i] - fee);
            holdY = std::max(holdY, holdN - prices[i]);
        }

        return holdN;
    }
};
