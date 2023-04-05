class Strategy {
public:
    virtual void addNum(int num) = 0;
    virtual double findMedian() = 0;
};

class HeapStrategy : public Strategy {
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

    double findMedian() {
        double m = m_lo.top();
        if (m_lo.size() == m_hi.size()) {
            m = (m + m_hi.top()) / 2;
        }
        return m;
    }

private:
    priority_queue<int, vector<int>, std::less<int>> m_lo;
    priority_queue<int, vector<int>, std::greater<int>> m_hi;
};

class SetStrategy : public Strategy {
public:
    void addNum(int num) {
        m_nums.insert(num);
        if (m_nums.size() == 1) {
            m_itr = m_nums.begin();
        }
        else if (m_nums.size() & 1) {
            if (*m_itr <= num) {
                m_itr = std::next(m_itr);
            }
        }
        else {
            if (num < *m_itr) {
                m_itr = std::prev(m_itr);
            }
        }
    }

    double findMedian() {
        double m = *m_itr;
        if (m_nums.size() % 2 == 0) {
            m = (m + *std::next(m_itr)) / 2;
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
        m_strategy = new HeapStrategy();
        //m_strategy = new SetStrategy();
    }

    void addNum(int num) {
        m_strategy->addNum(num);
    }

    double findMedian() {
        return m_strategy->findMedian();
    }

private:
    Strategy* m_strategy;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
