class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers)
        : m_pHead(NULL) {
        for (int i = 0; i < maxNumbers; ++i) {
            ListNode* pNode = new ListNode(i);
            pNode->next = m_pHead;
            m_pHead = pNode;
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (!m_pHead) {
            return -1;
        }

        int number = m_pHead->val;
        ListNode* pDel = m_pHead;
        m_pHead = m_pHead->next;
        delete pDel;

        return number;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        ListNode* pCur = m_pHead;
        while (pCur) {
            if (pCur->val == number) {
                return true;
            }
            pCur = pCur->next;
        }

        return false;
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (!check(number)) {
            ListNode* pNode = new ListNode(number);
            pNode->next = m_pHead;
            m_pHead = pNode;
        }
    }
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* m_pHead;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */