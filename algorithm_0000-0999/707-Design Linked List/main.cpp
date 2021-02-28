class MyLinkedList {
private:
    struct Node {
        Node()
            : val(0)
            , pPrev(nullptr)
            , pNext(nullptr) {
        }
        Node(int val_, Node* pPrev_, Node* pNext_)
            : val(val_)
            , pPrev(pPrev_)
            , pNext(pNext_) {
        }
        int val;
        Node* pPrev;
        Node* pNext;
    };

public:
    /** Initialize your data structure here. */
    MyLinkedList()
        : m_pHead(new Node())
        , m_pTail(new Node())
        , m_len(0) {
        m_pHead->pNext = m_pTail;
        m_pTail->pPrev = m_pHead;
    }
    
    ~MyLinkedList() {
        while (m_pHead->pNext != m_pTail) {
            erase(m_pHead->pNext);
        }
        
        delete m_pHead;
        delete m_pTail;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* pNode = getNode(index);
        return (pNode ? pNode->val : -1);
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        insert(m_pHead->pNext, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        insert(m_pTail, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == m_len) {
            addAtTail(val);
        }
        else {
            Node* pNode = getNode(index);
            if (pNode) {
                insert(pNode, val);
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* pNode = getNode(index);
        if (pNode) {
            erase(pNode);
        }
    }

private:
    Node* getNode(int index) {
        if (index < 0 || m_len <= index) {
            return nullptr;
        }

        Node* pNode;
        if (index < (m_len / 2)) {
            pNode = m_pHead->pNext;
            while (index--) {
                pNode = pNode->pNext;
            }
        }
        else {
            index = m_len - index;
            pNode = m_pTail;
            while (index--) {
                pNode = pNode->pPrev;
            }
        }
        return pNode;
    }

    void insert(Node* pNode, int val) {
        assert(pNode);

        Node* pTmp = new Node(val, pNode->pPrev, pNode);
        pTmp->pPrev->pNext = pTmp;
        pTmp->pNext->pPrev = pTmp;

        ++m_len;
    }
    
    void erase(Node* pNode) {
        assert(pNode);

        pNode->pPrev->pNext = pNode->pNext;
        pNode->pNext->pPrev = pNode->pPrev;
        delete pNode;

        --m_len;
    }

    Node* m_pHead;
    Node* m_pTail;
    int m_len;
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