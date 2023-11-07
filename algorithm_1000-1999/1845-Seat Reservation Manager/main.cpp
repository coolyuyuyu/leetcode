class SeatManager {
public:
    SeatManager(int n)
        : m_next(1) {
    }

    int reserve() {
        int ret;
        if (m_pq.empty()) {
            ret = m_next++;
        }
        else {
            ret = m_pq.top();
            m_pq.pop();
        }

        return ret;
    }

    void unreserve(int seatNumber) {
        m_pq.push(seatNumber);
    }

private:
    int m_next;
    priority_queue<int, vector<int>, std::greater<int>> m_pq;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
