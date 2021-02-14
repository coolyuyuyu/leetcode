class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity)
        : m_capacity(capacity) {
    }

    void enqueue(int element) {
        unique_lock lock(m_mtx);
        while (m_elements.size() == m_capacity) {
            m_fullCondition.wait(lock);
        }

        m_elements.push(element);

        m_emptyCondition.notify_one();
    }

    int dequeue() {
        unique_lock lock(m_mtx);
        while (m_elements.empty()) {
            m_emptyCondition.wait(lock);
        }

        int element = m_elements.front();
        m_elements.pop();

        m_fullCondition.notify_one();

        return element;
    }

    int size() {
        unique_lock lock(m_mtx);
        return m_elements.size();
    }

private:
    queue<int> m_elements;
    int m_capacity;

    mutex m_mtx;
    condition_variable m_emptyCondition;
    condition_variable m_fullCondition;
};