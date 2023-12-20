class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        std::partial_sort(prices.begin(), prices.begin() + 2, prices.end());

        int sum = prices[0] + prices[1];
        if (sum <= money) {
            return money - sum;
        }
        else {
            return money;
        }
    }
};
