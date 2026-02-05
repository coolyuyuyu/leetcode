class HitCounter {
public:
    HitCounter() {
    }

    void hit(int timestamp) {
        m_timestamps.push_back(timestamp);
    }

    int getHits(int timestamp) {
        auto lo = std::lower_bound(m_timestamps.begin(), m_timestamps.end(), timestamp - 300 + 1);
        auto hi = std::upper_bound(m_timestamps.begin(), m_timestamps.end(), timestamp);
        return std::distance(lo, hi);
    }

private:
    vector<int> m_timestamps;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
