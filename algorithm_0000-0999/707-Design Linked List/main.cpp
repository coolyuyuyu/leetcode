class MyLinkedList {
public:
    MyLinkedList()
        : m_head(new Node())
        , m_tail(new Node())
        , m_size(0) {
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }

    int get(int index) {
        Node* node = getNode(index);
        return (node ? node->val : -1);
    }

    void addAtHead(int val) {
        insertBefore(m_head->next, val);
    }

    void addAtTail(int val) {
        insertBefore(m_tail, val);
    }

    void addAtIndex(int index, int val) {
        Node* next = (index == m_size ? m_tail : getNode(index));
        if (next) {
            insertBefore(next, val);
        }
    }

    void deleteAtIndex(int index) {
        Node* node = getNode(index);
        if (node) {
            erase(node);
        }
    }

private:
    struct Node {
        int val;
        Node* next;
        Node* prev;

        Node()
            : val(0)
            , next(nullptr)
            , prev(nullptr) {
        }
        Node(int v, Node* n, Node* p)
            : val(v)
            , next(n)
            , prev(p) {
        }
    };

    Node* getNode(int index) {
        if (m_size <= index) { return nullptr; }

        Node* node;
        if (index < m_size / 2) {
            node = m_head->next;
            while (0 < index--) {
                node = node->next;
            }
        }
        else {
            index = m_size - index - 1;
            node = m_tail->prev;
            while (0 < index--) {
                node = node->prev;
            }
        }

        return node;
    }

    void insertBefore(Node* node, int val) {
        Node* inserted = new Node(val, node, node->prev);
        inserted->next->prev = inserted;
        inserted->prev->next = inserted;
        ++m_size;
    }

    void erase(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        --m_size;
    }

    Node* m_head;
    Node* m_tail;
    int m_size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
