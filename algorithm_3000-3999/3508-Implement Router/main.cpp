class Router {
public:
    Router(int memoryLimit)
        : m_capacity(memoryLimit) {
    }

    bool addPacket(int source, int destination, int timestamp) {
        if (m_set.emplace(source, destination, timestamp).second == false) {
            return false;
        }

        m_queue.emplace(source, destination, timestamp);
        auto& [storage, _] = m_dst2pkts[destination];
        storage.push_back(timestamp);

        if (m_queue.size() > m_capacity) {
            forwardPacket();
        }

        return true;
    }

    vector<int> forwardPacket() {
        if (m_queue.empty()) {
            return {};
        }

        auto [src, dst, t] = m_queue.front();
        m_queue.pop();
        m_set.erase({src, dst, t});

        auto& [_, delCnt] = m_dst2pkts[dst];
        ++delCnt;

        return {src, dst, t};
    }

    int getCount(int destination, int startTime, int endTime) {
        const auto& [storage, delCnt] = m_dst2pkts[destination];

        auto itrLo = std::lower_bound(storage.begin() + delCnt, storage.end(), startTime);
        auto itrHi = std::upper_bound(storage.begin() + delCnt, storage.end(), endTime);
        return std::distance(itrLo, itrHi);
    }

private:
    int m_capacity;
    queue<tuple<int, int, int>> m_queue;
    set<tuple<int, int, int>> m_set;
    unordered_map<int, pair<vector<int>, int>> m_dst2pkts;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
