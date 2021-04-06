class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        typedef pair<int, int> Order; // <price, amount>

        auto compBuy = [](const Order& o1, const Order& o2) {
            return less<int>()(o1.first, o2.first);
        };
        auto compSell = [](const Order& o1, const Order& o2) {
            return greater<int>()(o1.first, o2.first);
        };
        priority_queue<Order, vector<Order>, decltype(compBuy)> pqBuy(compBuy); // max_heap
        priority_queue<Order, vector<Order>, decltype(compSell)> pqSell(compSell); // min_heap

        for (vector<int>& o : orders) {
            int price = o[0];
            int amount = o[1];
            if (o[2] == 0) { // buy
                while (!pqSell.empty() && pqSell.top().first <= price && 0 < amount) {
                    Order order = pqSell.top();
                    pqSell.pop();

                    int decAmount = min(order.second, amount);
                    order.second -= decAmount;
                    amount -= decAmount;

                    if (0 < order.second) {
                        pqSell.push(order);
                    }
                }
                if (0 < amount) {
                    pqBuy.emplace(price, amount);
                }
            }
            else { // sell
                while (!pqBuy.empty() && price <= pqBuy.top().first && 0 < amount) {
                    Order order = pqBuy.top();
                    pqBuy.pop();

                    int decAmount = min(order.second, amount);
                    order.second -= decAmount;
                    amount -= decAmount;

                    if (0 < order.second) {
                        pqBuy.push(order);
                    }
                }
                if (0 < amount) {
                    pqSell.emplace(price, amount);
                }
            }

        }

        int amount = 0;
        for (; !pqBuy.empty(); pqBuy.pop()) {
            //amount += pqBuy.top().second;

            amount += (pqBuy.top().second % 1000000007);
            amount %= (1000000007);
        }
        for (; !pqSell.empty(); pqSell.pop()) {
            //amount += pqSell.top().second ;

            amount += (pqSell.top().second % 1000000007);
            amount %= (1000000007);
        }
        return amount;
    }
};