class AuctionSystem {
public:
    AuctionSystem() {
    }

    void addBid(int userId, int itemId, int bidAmount) {
        updateBid(userId, itemId, bidAmount);
    }

    void updateBid(int userId, int itemId, int newAmount) {
        if (m_useritem2amount.find({userId, itemId}) != m_useritem2amount.end()) {
            int oldAmount = m_useritem2amount[{userId, itemId}];
            m_useritem2amount.erase({userId, itemId});
            m_item2amountuser[itemId].erase({oldAmount, userId});
        }

        m_useritem2amount[{userId, itemId}] = newAmount;
        m_item2amountuser[itemId].emplace(newAmount, userId);
    }

    void removeBid(int userId, int itemId) {
        int amount = m_useritem2amount[{userId, itemId}];
        m_useritem2amount.erase({userId, itemId});
        m_item2amountuser[itemId].erase({amount, userId});
        if (m_item2amountuser[itemId].empty()) {
            m_item2amountuser.erase(itemId);
        }
    }

    int getHighestBidder(int itemId) {
        if (m_item2amountuser.find(itemId) == m_item2amountuser.end()) {
            return -1;
        }

        return m_item2amountuser[itemId].rbegin()->second;
    }

private:
    map<pair<int, int>, int> m_useritem2amount;
    map<int, set<pair<int, int>>> m_item2amountuser;
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
