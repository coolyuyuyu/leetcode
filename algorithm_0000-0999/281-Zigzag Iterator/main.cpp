class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) { m_queue.emplace(v1.begin(), v1.end()); };
        if (!v2.empty()) { m_queue.emplace(v2.begin(), v2.end()); };
    }

    int next() {
        auto [itr, end] = m_queue.front();
        m_queue.pop();

        int ret = *itr++;
        if (itr != end) {
            m_queue.emplace(itr, end);
        }

        return ret;
    }

    bool hasNext() {
        return !m_queue.empty();
    }

private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> m_queue;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
