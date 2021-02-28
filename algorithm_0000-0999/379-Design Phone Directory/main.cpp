class PhoneDirectory {
private:
    struct Node {
        Node()
            : val()
            , pNext(nullptr) {
        }
        Node(int val_, Node* pNext_)
            : val(val_)
            , pNext(pNext_) {
        }
        int val;
        Node* pPrev;
        Node* pNext;
    };

public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers)
        : m_pHead(nullptr) {
        for (int i = 0; i < maxNumbers; ++i) {
            Node* pNode = new Node(i, m_pHead);
            m_pHead = pNode;
        }
    }

    ~PhoneDirectory() {
        while (m_pHead) {
            Node* pDel = m_pHead;
            m_pHead = pDel->pNext;
            delete pDel;
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (!m_pHead) {
            return -1;
        }

        int number = m_pHead->val;
        Node* pDel = m_pHead;
        m_pHead = m_pHead->pNext;
        delete pDel;

        return number;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        for (Node* pCur = m_pHead; pCur; pCur = pCur->pNext) {
            if (pCur->val == number) {
                return true;
            }
        }

        return false;
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (!check(number)) {
            Node* pNode = new Node(number, m_pHead);
            m_pHead = pNode;
        }
    }

private:
    Node* m_pHead;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */