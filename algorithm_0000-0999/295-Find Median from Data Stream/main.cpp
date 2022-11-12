class MediaFinderStrategy {
public:
    virtual void addNum(int num) = 0;
    virtual double findMedian() const = 0;
};

class MediaFinderStrategyByHeap : public MediaFinderStrategy {
public:   
    void addNum(int num) {
        m_lo.push(num);
        m_hi.push(m_lo.top());
        m_lo.pop();

        if (m_lo.size() < m_hi.size()) {
            m_lo.push(m_hi.top());
            m_hi.pop();
        }
    }
    
    double findMedian() const {
        double m = m_lo.top();
        if (m_lo.size() == m_hi.size()) {
            m = (m + m_hi.top()) * 0.5;
        }
        return m;
    }

private:
    std::priority_queue<int> m_lo; // minheap
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_hi; // max_heap
};

class MediaFinderStrategyByMultiSet : public MediaFinderStrategy {
public:   
    void addNum(int num) {
        size_t n = m_nums.size();
        m_nums.insert(num);
        if (n == 0) {            
            m_itr = m_nums.begin();
            return;
        }

        if (num == *m_itr) {
            if (n & 1) {
            }
            else {
                ++m_itr;
            }
        }
        else if (num < *m_itr) {
            if (n & 1) {
                --m_itr;
            }
            else {
            }
        }
        else {
            if (n & 1) {
            }
            else {
                ++m_itr;
            }
        }
    }
    
    double findMedian() const {
        size_t n = m_nums.size();
        double m = *m_itr;
        if (n % 2 == 0) {
            m = (m + *std::next(m_itr)) * 0.5;
        }
        return m;
    }

private:
    multiset<int> m_nums;
    multiset<int>::const_iterator m_itr;
};

class MedianFinder {
public:
    MedianFinder() {
        //m_strategy = new MediaFinderStrategyByHeap();

        m_strategy = new MediaFinderStrategyByMultiSet();
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
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 