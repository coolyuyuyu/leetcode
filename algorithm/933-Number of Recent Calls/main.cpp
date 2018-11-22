class RecentCounter {
public:
    RecentCounter() {
    }

    int ping(int t) {
        m_times.push(t);
        while (!m_times.empty()) {
            if (t - m_times.front() > 3000) {
                m_times.pop();
            }
            else {
                break;
            }
        }

        return m_times.size();
    }
    
private:
    queue<int> m_times;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
