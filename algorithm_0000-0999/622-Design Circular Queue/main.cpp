class MyCircularQueue {
public:
    MyCircularQueue(int k)
        : m_data(new int[k])
        , m_index(0)
        , m_size(0)
        , m_capacity(k) {
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        else {
            m_data[(m_index + m_size++) % m_capacity] = value;
            return true;
        }
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        else {
            m_index = (m_index + 1) % m_capacity;
            --m_size;
            return true;
        }
    }

    int Front() {
        return isEmpty() ? -1 : m_data[m_index];
    }

    int Rear() {
        return isEmpty() ? -1 : m_data[(m_index + m_size - 1) % m_capacity];
    }

    bool isEmpty() {
        return (m_size ==  0);
    }

    bool isFull() {
        return (m_size ==  m_capacity);
    }

private:
    int* m_data;
    int m_index;
    int m_size;
    int m_capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
