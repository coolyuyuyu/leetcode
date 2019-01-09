class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(size_t capacity)
        : m_data(capacity)
        , m_size(0)
        , m_indexFront(capacity - 1)
        , m_indexRear(0) {
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        m_data[m_indexFront] = value;
        m_indexFront = (m_indexFront + m_data.size() - 1) % m_data.size();

        ++m_size;

        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        m_data[m_indexRear] = value;
        m_indexRear = (m_indexRear + 1) % m_data.size();

        ++m_size;

        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        m_indexFront = (m_indexFront + 1) % m_data.size();

        --m_size;

        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

         m_indexRear = (m_indexRear + m_data.size() - 1) % m_data.size();

        --m_size;

        return true;
    }

    /** Get the front item from the deque. */
    int getFront() const {
        if (isEmpty()) {
            return -1;
        }

        return m_data[(m_indexFront + 1) % m_data.size()];
    }

    /** Get the last item from the deque. */
    int getRear() const {
        if (isEmpty()) {
            return -1;
        }

        return m_data[(m_indexRear + m_data.size() - 1) % m_data.size()];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() const {
        return (m_size == 0);
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() const {
        return (m_size == m_data.size());
    }

private:
    vector<int> m_data;
    size_t m_size;
    size_t m_indexFront;
    size_t m_indexRear;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */