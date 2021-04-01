class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : m_k(k)
        , m_comp(greater<int>())
        , m_pq(m_comp) {
        for (int val : nums) {
            add(val);
        }
    }

    int add(int val) {
        // m_pq: min_heap
        if (m_pq.size() < m_k) {
            m_pq.push(val);
        }
        else if (!m_comp(m_pq.top(), val)) {
            m_pq.pop();
            m_pq.push(val);
        }

        return m_pq.top();
    }

private:
    int m_k;
    function<bool(int, int)> m_comp;
    priority_queue<int, vector<int>, function<bool(int, int)>> m_pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */