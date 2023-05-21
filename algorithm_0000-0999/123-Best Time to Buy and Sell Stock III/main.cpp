class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN;    // the maximum profit after 1st hold
        int sold1 = 0;          // the maximum profit after 1st hold, 1st sold
        int hold2 = INT_MIN;    // the maximum profit after 1st hold, 1st sold, 2nd hold
        int sold2 = 0;          // the maximum profit after 1st hold, 1st sold, 2nd hold, 2nd sold
        for (int i = 0; i < prices.size(); ++i) {
            int tmpHold1 = hold1, tmpSold1 = sold1, tmpHold2 = hold2, tmpSold2 = sold2;
            hold1 = std::max(tmpHold1, 0 - prices[i]);
            sold1 = std::max(tmpSold1, tmpHold1 + prices[i]);
            hold2 = std::max(tmpHold2, tmpSold1 - prices[i]);
            sold2 = std::max(tmpSold2, tmpHold2 + prices[i]);
        }

        return std::max(sold1, sold2);
    }
};
