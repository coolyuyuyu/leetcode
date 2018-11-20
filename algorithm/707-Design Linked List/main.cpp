class MyLinkedList {
    friend ostream& operator<<(ostream& os, const MyLinkedList& linkedList) {
        ListNode* node = linkedList.m_head->next;
        if (node != linkedList.m_tail) {
            cout << node->val;
            node = node->next;
        }

        while (node != linkedList.m_tail) {
            cout << " " << node->val;
            node = node->next;
        }

        return os;
    }

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        m_head = new ListNode;
        m_tail = new ListNode;
        m_head->next = m_head->prev = m_tail;
        m_tail->next = m_tail->prev = m_head;
    }

    ~MyLinkedList() {
        while (m_size) {
            deleteAtIndex(0);
        }

        delete m_head;
        delete m_tail;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* node = getNode(index);
        return (node ? node->val : -1);
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = m_head->next;
        node->prev = m_head;
        m_head->next->prev = node;
        m_head->next = node;

        ++m_size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        node->next = m_tail;
        node->prev = m_tail->prev;
        m_tail->prev->next = node;
        m_tail->prev = node;

        ++m_size;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
        }
        else if (index < m_size) {
            ListNode* node = new ListNode(val);
            ListNode* targetNode = getNode(index);
            node->next = targetNode;
            node->prev = targetNode->prev;
            targetNode->prev->next = node;
            targetNode->prev = node;

            ++m_size;
        }
        else if (index == m_size) {
            addAtTail(val);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (m_size < index + 1) {
            return;
        }

        ListNode* node = getNode(index);
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;

        --m_size;
    }

private:
    class ListNode {
    public:
        ListNode(int val_ = 0) : val(val_) {}
        int val;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
    };

    ListNode* getNode(int index) {
        if (index < 0 || m_size <= index) {
            return nullptr;
        }

        ListNode* node;
        int mid = m_size / 2;
        if (index < mid) {
            node = m_head->next;
            while (index--) {
                node = node->next;
            }
        }
        else {
            index = m_size - index - 1;
            node = m_tail->prev;
            while (index--) {
                node = node->prev;
            }
        }

        return node;
    }

    size_t m_size = 0;
    ListNode* m_head;
    ListNode* m_tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
