class RecentCounter {
public:
    RecentCounter() {
    }

    int ping(int t) {
        while (!m_times.empty() && 3000 < (t - m_times.front())) {
            m_times.pop();
        }
        m_times.push(t);

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