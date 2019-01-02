class MediaFinderStrategy {
public:
    virtual void addNum(int num) = 0;
    virtual double findMedian() const = 0;
};

class MediaFinderStrategyByHeap : public MediaFinderStrategy {
public:
    MediaFinderStrategyByHeap() {
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

    double findMedian() const {
        return m_lo.size() > m_hi.size() ? m_lo.top() : (m_lo.top() + m_hi.top()) * 0.5;
    }

private:
    priority_queue<int> m_lo; // max-heap
    priority_queue<int, vector<int>, greater<int>> m_hi; // min-heap
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        m_strategy = new MediaFinderStrategyByHeap();
    }

    ~MedianFinder() {
        delete m_strategy;
    }

    void addNum(int num) {
        m_strategy->addNum(num);
    }

    double findMedian() {
        return m_strategy->findMedian();
    }

private:
    MediaFinderStrategy* m_strategy;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */