class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        m_lo.emplace(num);
        m_hi.emplace(m_lo.top());
        m_lo.pop();

        if (m_lo.size() < m_hi.size()) {
            m_lo.emplace(m_hi.top());
            m_hi.pop();
        }
    }

    double findMedian() {
        return m_lo.size() > m_hi.size() ? m_lo.top() : (m_lo.top() + m_hi.top()) * 0.5;
    }

private:
    priority_queue<int> m_lo; // max-heap
    priority_queue<int, vector<int>, greater<int>> m_hi; // min-heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */