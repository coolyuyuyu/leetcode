class FrontMiddleBackQueue {
private:
    struct Node {
        Node()
            : val()
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
    FrontMiddleBackQueue()
        : m_pHead(new Node())
        , m_pTail(new Node())
        , m_pMid(nullptr)
        , m_len(0) {
        m_pHead->pNext = m_pTail;
        m_pTail->pPrev = m_pHead;
    }

    ~FrontMiddleBackQueue() {
        while (!empty()) {
            popFront();
        }

        delete m_pHead;
        delete m_pTail;
    }

    bool empty() const {
        return (m_len == 0);
    }

    size_t size() const {
        return m_len;
    }

    void pushFront(int val) {
        Node* pNode = insert(m_pHead->pNext, val);
        if (m_len == 0) {
            m_pMid = pNode;
        }
        else if (m_len % 2 == 1) {
            m_pMid = m_pMid->pPrev;
        }

        ++m_len;
    }

    void pushMiddle(int val) {
        if (m_len == 0) {
            pushFront(val);
        }
        else {
            if (m_len % 2 == 0) {
                m_pMid = insert(m_pMid->pNext, val);
            }
            else {
                m_pMid = insert(m_pMid, val);
            }
            ++m_len;
        }
    }

    void pushBack(int val) {
        Node* pNode = insert(m_pTail, val);
        if (m_len == 0) {
            m_pMid = pNode;
        }
        else if (m_len % 2 == 0) {
            m_pMid = m_pMid->pNext;
        }

        ++m_len;
    }

    int popFront() {
        if (m_len == 0) {
            return -1;
        }

        if (m_len == 1) {
            m_pMid = nullptr;
        }
        else if (m_len % 2 == 0) {
            m_pMid = m_pMid->pNext;
        }
        int val = erase(m_pHead->pNext);

        -- m_len;

        return val;
    }

    int popMiddle() {
        if (m_len == 0) {
            return -1;
        }

        Node* pTmp = m_pMid;
        if (m_len == 1) {
            m_pMid = nullptr;
        }
        else if (m_len % 2 == 0) {
            m_pMid = m_pMid->pNext;
        }
        else {
            m_pMid = m_pMid->pPrev;
        }
        int val = erase(pTmp);

        --m_len;

        return val;
    }

    int popBack() {
        if (m_len == 0) {
            return -1;
        }

        if (m_len == 1) {
            m_pMid = nullptr;
        }
        else if (m_len % 2 == 1){
            m_pMid = m_pMid->pPrev;
        }
        int val = erase(m_pTail->pPrev);

        --m_len;

        return val;
    }

private:
    Node* insert(Node* pNode, int val) {
        Node* pTmp = new Node(val, pNode->pPrev, pNode);
        pTmp->pPrev->pNext = pTmp;
        pTmp->pNext->pPrev = pTmp;
        return pTmp;
    }

    int erase(Node* pNode) {
        assert(pNode != m_pHead && pNode != m_pTail);
        pNode->pPrev->pNext = pNode->pNext;
        pNode->pNext->pPrev = pNode->pPrev;

        int val = pNode->val;
        delete pNode;

        return val;
    }

    Node* m_pHead;
    Node* m_pTail;
    Node* m_pMid;
    size_t m_len;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */