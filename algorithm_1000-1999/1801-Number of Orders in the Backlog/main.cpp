class Solution {
public:
    int M = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::less<pair<int, int>>> buyPQ; // <price, amount>
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> sellPQ; // <price, amount>

        for (const auto& order : orders) {
            int price = order[0], amount = order[1], type = order[2];
            if (type == 0) { // buy
                while (!sellPQ.empty() && price >= sellPQ.top().first && amount > 0) {
                    auto [sellPrice, sellAmount] = sellPQ.top();
                    sellPQ.pop();

                    int tradeAmount = std::min(sellAmount, amount);
                    sellAmount -= tradeAmount;
                    amount -= tradeAmount;
                    if (sellAmount) {
                        sellPQ.emplace(sellPrice, sellAmount);
                    }
                }
                if (amount) {
                    buyPQ.emplace(price, amount);
                }
            }
            else {
                while (!buyPQ.empty() && amount > 0 && price <= buyPQ.top().first) {
                    auto [buyPrice, buyAmount] = buyPQ.top();
                    buyPQ.pop();

                    int tradeAmount = std::min(buyAmount, amount);
                    buyAmount -= tradeAmount;
                    amount -= tradeAmount;
                    if (buyAmount) {
                        buyPQ.emplace(buyPrice, buyAmount);
                    }
                }
                if (amount) {
                    sellPQ.emplace(price, amount);
                }
            }
        }

        int ret = 0;
        while (!buyPQ.empty()) {
            ret += buyPQ.top().second;
            ret %= M;
            buyPQ.pop();
        }
        while (!sellPQ.empty()) {
            ret += sellPQ.top().second;
            ret %= M;
            sellPQ.pop();
        }

        return ret;
    }
};
