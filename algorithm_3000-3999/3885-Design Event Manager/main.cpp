class EventManager {
public:
    EventManager(vector<vector<int>>& events) {
        for (const auto& event : events) {
            int id = event[0], prio = event[1];
            m_id2prio[id] = prio;
            m_maxPQ.emplace(prio, -id);
        }
    }

    void updatePriority(int eventId, int newPriority) {
        m_id2prio[eventId] = newPriority;
        m_maxPQ.emplace(newPriority, -eventId);
    }

    int pollHighest() {
        while (!m_maxPQ.empty()) {
            auto [prio, negId] = m_maxPQ.top();
            m_maxPQ.pop();

            int id = -negId;
            auto itr = m_id2prio.find(id);
            if (itr != m_id2prio.end() && itr->second == prio) {
                m_id2prio.erase(itr);
                return id;
            }
        }

        return -1;
    }

private:
    unordered_map<int, int> m_id2prio;
    priority_queue<pair<int, int>> m_maxPQ; // <prio, -id>
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
