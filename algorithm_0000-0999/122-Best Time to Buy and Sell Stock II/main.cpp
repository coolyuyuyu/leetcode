class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] < prices[i]) {
                result += (prices[i] - prices[i - 1]);
            }
        }

        return result;
    }
};