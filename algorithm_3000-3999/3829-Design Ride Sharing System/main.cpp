class RideSharingSystem {
public:
    RideSharingSystem() {
    }

    void addRider(int riderId) {
        m_riders.push(riderId);
        m_availRiders.insert(riderId);
    }

    void addDriver(int driverId) {
        m_drivers.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        while (!m_riders.empty() && m_cancelRiders.find(m_riders.front()) != m_cancelRiders.end()) {
            int riderId = m_riders.front();
            m_riders.pop();
            m_cancelRiders.erase(riderId);
        }

        if (m_riders.empty() || m_drivers.empty()) {
            return {-1, -1};
        }
        else {
            int riderId = m_riders.front();
            m_riders.pop();
            m_availRiders.erase(riderId);
            int driverId = m_drivers.front();
            m_drivers.pop();
            return {driverId, riderId};
        }
    }

    void cancelRider(int riderId) {
        if (m_availRiders.find(riderId) != m_availRiders.end()) {
            m_availRiders.erase(riderId);
            m_cancelRiders.insert(riderId);
        }
    }

private:
    queue<int> m_riders;
    queue<int> m_drivers;
    unordered_set<int> m_availRiders;
    unordered_set<int> m_cancelRiders;
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
