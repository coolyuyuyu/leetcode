class MKAverage {
public:
    MKAverage(int m, int k)
        : m_m(m)
        , m_k(k)
        , m_sumMid(0) {
    }

    void addElement(int num) {
        m_q.push(num);

        m_lft.insert(num);
        if (m_lft.size() <= m_k) { return; }
        m_sumMid += shiftRht(m_lft, m_mid);
        m_sumMid -= shiftRht(m_mid, m_rht);
        if (m_rht.size() <= m_k) { return; }
        m_sumMid += shiftLft(m_mid, m_rht);

        if (m_q.size() <= m_m) { return; }

        int toRemove = m_q.front();
        m_q.pop();
        if (m_lft.find(toRemove) != m_lft.end()) {
            m_lft.erase(m_lft.find(toRemove));
            m_sumMid -= shiftLft(m_lft, m_mid);

        }
        else if (m_rht.find(toRemove) != m_rht.end()) {
            m_rht.erase(m_rht.find(toRemove));
            m_sumMid -= shiftRht(m_mid, m_rht);
        }
        else {
            assert(m_mid.find(toRemove) != m_mid.end());
            m_mid.erase(m_mid.find(toRemove));
            m_sumMid -= toRemove;
        }
    }

    int calculateMKAverage() {
        if (m_q.size() < m_m) { return -1; }
        return  m_sumMid / m_mid.size();
    }

private:
    int shiftLft(multiset<int>& ms1, multiset<int>& ms2) {
        auto itr = ms2.begin();
        int ret = *itr;
        ms1.insert(ret);
        ms2.erase(itr);
        return ret;
    }

    int shiftRht(multiset<int>& ms1, multiset<int>& ms2) {
        auto itr = std::prev(ms1.end());
        int ret = *itr;
        ms2.insert(ret);
        ms1.erase(itr);
        return ret;
    }

    int m_m;
    int m_k;

    multiset<int> m_lft, m_mid, m_rht;
    long long m_sumMid;

    queue<int> m_q;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
