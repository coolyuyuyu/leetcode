class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<size_t> stk;
        for (size_t i = 0; i < prices.size(); ++i) {
            while (!stk.empty() && prices[i] <= prices[stk.top()] ) {
                prices[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }

        return prices;
    }
};
