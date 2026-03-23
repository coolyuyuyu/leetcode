class ByDoublyList {
public:
    ByDoublyList(int n)
        : m_bucketSize(std::ceil(std::sqrt(n))) {
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

class BySinglyList {
public:
    BySinglyList(int n)
        : m_bucketSize(std::ceil(std::sqrt(n)))
        , m_end(m_data.before_begin()) {
        auto itr = m_data.before_begin();
        for (int elem = 1; elem <= n; ++elem) {
            if ((elem - 1) % m_bucketSize == 0) {
                m_itrs.push_back(itr);
            }
            itr = m_data.insert_after(itr, elem);
        }
        m_end = itr;
    }

    int fetch(int k) {
        --k;
        int bucketIdx = k / m_bucketSize;
        auto itr = m_itrs[bucketIdx];
        for (int dist = k % m_bucketSize; 0 < dist--;) {
            itr = std::next(itr);
        }

        int ret = *std::next(itr);

        m_end = m_data.insert_after(m_end, ret);
        for (int i = bucketIdx + 1; i < m_itrs.size(); ++i) {
            m_itrs[i] = std::next(m_itrs[i]);
        }
        m_data.erase_after(itr);

        return ret;
    }

private:
    const int m_bucketSize;
    forward_list<int> m_data;
    std::vector<forward_list<int>::const_iterator> m_itrs;
    forward_list<int>::const_iterator m_end;
};

//typedef ByDoublyList MRUQueue;
typedef BySinglyList MRUQueue;


/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
