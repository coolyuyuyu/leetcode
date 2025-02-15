class MRUQueue {
public:
    MRUQueue(int n)
        : m_bucketSize(std::sqrt(n)) {
        for (int elem = 1; elem <= n; ++elem) {
            m_data.push_back(elem);
            if ((elem - 1) % m_bucketSize == 0) {
                m_itrs.push_back(std::prev(m_data.end()));
            }
        }
    }

    int fetch(int k) {
        --k;
        int bucketIdx = k / m_bucketSize;
        auto itr = m_itrs[bucketIdx];
        for (int dist = k % m_bucketSize; 0 < dist--;) {
            itr = std::next(itr);
        }

        m_data.push_back(*itr);
        for (int i = bucketIdx + ((k % m_bucketSize) == 0 ? 0 : 1); i < m_itrs.size(); ++i) {
            m_itrs[i] = std::next(m_itrs[i]);
        }
        m_data.erase(itr);

        return m_data.back();
    }

private:
    const int m_bucketSize;
    list<int> m_data;
    std::vector<list<int>::const_iterator> m_itrs;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
