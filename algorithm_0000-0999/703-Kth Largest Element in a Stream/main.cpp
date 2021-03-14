class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : m_k(k) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (m_pq.size() < m_k) {
            m_pq.push(val);
        }
        else {
            assert(!m_pq.empty());
            if (m_pq.top() < val) {
                m_pq.pop();
                m_pq.push(val);
            }
        }

        return m_pq.top();
    }

private:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> m_pq; // min_heap
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */