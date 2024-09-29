class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(size_t capacity)
        : m_size(0)
        , m_capacity(capacity)
        , m_index(0)
        , m_data(new int[m_capacity]) {
    }

    ~MyCircularDeque() {
        delete[] m_data;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        else {
            m_index = (m_index + m_capacity - 1) % m_capacity;
            m_data[m_index] = value;
            ++m_size;
            return true;
        }
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        else {
            m_data[(m_index + m_size) % m_capacity] = value;
            ++m_size;
            return true;
        }
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        else {
            m_index = (m_index + 1) % m_capacity;
            --m_size;
            return true;
        }
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        else {
            --m_size;
            return true;
        }
    }

    /** Get the front item from the deque. */
    int getFront() {
        return (isEmpty() ? -1 : m_data[m_index]);
    }

    /** Get the last item from the deque. */
    int getRear() {
        return (isEmpty() ? -1 : m_data[(m_index + m_size - 1) % m_capacity]);
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (m_size == 0);
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (m_size == m_capacity);
    }

private:
    size_t m_size;
    size_t m_capacity;
    size_t m_index;
    int* m_data;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
