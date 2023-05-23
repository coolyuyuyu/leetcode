class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : m_k(k)
        , m_comp(std::greater<int>())
        , m_pq(m_comp) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (m_pq.size() < m_k) {
            m_pq.push(val);
        }
        else if (m_comp(val, m_pq.top())) {
            m_pq.push(val);
            m_pq.pop();
        }

        return m_pq.top();
    }

private:
    int m_k;
    std::function<bool(int, int)> m_comp;
    priority_queue<int, vector<int>, std::function<bool(int, int)>> m_pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
