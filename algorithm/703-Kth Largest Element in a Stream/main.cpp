class KthLargest {
public:
    KthLargest(int k, vector<int> nums)
        : m_capacity(k)
    {
        assert(k >= 1);

        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (m_pq.size() < m_capacity) {
            m_pq.push(val);
        }
        else {
            if (m_pq.top() < val) {
                m_pq.pop();
                m_pq.push(val);
            }
        }

        return m_pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> m_pq;
    size_t m_capacity;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
