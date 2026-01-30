class OrderManagementSystem {
public:
    OrderManagementSystem() {
    }

    void addOrder(int orderId, string orderType, int price) {
        bool type = (orderType == "sell");
        m_id2typeprice[orderId] = {type, price};
        auto& price2ids = (type ? m_price2sids : m_price2bids);
        price2ids[price].insert(orderId);
    }

    void modifyOrder(int orderId, int newPrice) {
        auto [type, oldPrice] = m_id2typeprice[orderId];
        cancelOrder(orderId);
        addOrder(orderId, type ? "sell" : "buy", newPrice);
    }

    void cancelOrder(int orderId) {
        auto [type, price] = m_id2typeprice[orderId];
        auto& price2ids = (type ? m_price2sids : m_price2bids);
        price2ids[price].erase(orderId);
        m_id2typeprice.erase(orderId);
    }

    vector<int> getOrdersAtPrice(string orderType, int price) {
        auto& price2ids = (orderType == "buy" ? m_price2bids : m_price2sids);
        auto& ids = price2ids[price];
        return vector<int>(ids.begin(), ids.end());
    }

private:
    unordered_map<int, pair<bool, int>> m_id2typeprice;
    unordered_map<int, unordered_set<int>> m_price2bids;
    unordered_map<int, unordered_set<int>> m_price2sids;
};

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem* obj = new OrderManagementSystem();
 * obj->addOrder(orderId,orderType,price);
 * obj->modifyOrder(orderId,newPrice);
 * obj->cancelOrder(orderId);
 * vector<int> param_4 = obj->getOrdersAtPrice(orderType,price);
 */
