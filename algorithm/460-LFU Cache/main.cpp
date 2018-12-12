class LFUCache {
public:
    LFUCache(size_t capacity)
        : m_capacity(capacity)
        , m_size(0)
        , m_minFrequency(0)
        , m_nodes(new CacheNode[m_capacity]) {
    }

    ~LFUCache() {
        delete[] m_nodes;
    }

    int get(int key) const {
        auto nodeItr = m_nodeHash.find(key);
        if (nodeItr == m_nodeHash.end()) {
            return -1;
        }

        CacheNode* pNode = nodeItr->second;
        pNode->detach();

        auto dllistItr = m_dllistHash.find(pNode->frequency);
        assert(dllistItr != m_dllistHash.end());
        if (dllistItr->second.empty()) {
            m_dllistHash.erase(dllistItr);

            if (pNode->frequency == m_minFrequency) {
                m_minFrequency += 1;
            }
        }

        ++pNode->frequency;
        m_dllistHash[pNode->frequency].pushFront(pNode);

        return pNode->val;
    }

    void put(int key, int value) {
        if (m_capacity == 0) {
            return;
        }

        auto nodeItr = m_nodeHash.find(key);
        if (nodeItr == m_nodeHash.end()) {
            CacheNode* pNode = nullptr;
            if (m_size < m_capacity) {
                pNode = m_nodes + m_size;
                ++m_size;
            }
            else {
                DoublyLinkedList& dllist = m_dllistHash[m_minFrequency];
                assert(!dllist.empty());

                pNode = dllist.back();
                dllist.popBack();

                m_nodeHash.erase(pNode->key);
                if (dllist.empty()) {
                    m_dllistHash.erase(m_minFrequency);
                }
            }

            pNode->key = key;
            pNode->val = value;
            pNode->frequency = 0;

            m_nodeHash[key] = pNode;
            m_dllistHash[pNode->frequency].pushFront(pNode);

            m_minFrequency = 0;
        }
        else {
            CacheNode* pNode = nodeItr->second;
            pNode->detach();

            auto dllistItr = m_dllistHash.find(pNode->frequency);
            assert(dllistItr != m_dllistHash.end());
            if (dllistItr->second.empty()) {
                m_dllistHash.erase(pNode->frequency);

                if (pNode->frequency == m_minFrequency) {
                    m_minFrequency += 1;
                }
            }

            pNode->val = value;
            pNode->frequency += 1;

            m_dllistHash[pNode->frequency].pushFront(pNode);
        }
    }

    size_t capacity() const {
        return m_capacity;
    }

    size_t size() const {
        return m_size;
    }

private:
    class CacheNode {
    public:
        CacheNode()
            : pNext(nullptr)
            , pPrev(nullptr) {
        }

        void detach() {
            assert(pNext && pPrev);
            pNext->pPrev = pPrev;
            pPrev->pNext = pNext;
            pNext = pPrev = nullptr;
        }

        int key;
        int val;
        int frequency;

        CacheNode* pNext;
        CacheNode* pPrev;
    };

    class DoublyLinkedList {
    public:
        DoublyLinkedList()
            : pHead(new CacheNode())
            , pTail(new CacheNode()) {
            pHead->pNext = pTail;
            pTail->pPrev = pHead;
        }

        ~DoublyLinkedList() {
            delete pHead;
            delete pTail;
        }

        bool empty() const {
            return pHead->pNext == pTail;
        }

        void pushFront(CacheNode* pNode) {
            pNode->pNext = pHead->pNext;
            pNode->pNext->pPrev = pNode;
            pHead->pNext = pNode;
            pNode->pPrev = pHead;
        }

        void popBack() {
            assert(!empty());
            pTail->pPrev = pTail->pPrev->pPrev;
            pTail->pPrev->pNext = pTail;
        }

        CacheNode* back() const {
            assert(!empty());
            return pTail->pPrev;
        }

        CacheNode* pHead;
        CacheNode* pTail;
    };

    size_t m_capacity;
    size_t m_size;

    mutable size_t m_minFrequency;

    CacheNode* m_nodes;
    unordered_map<int, CacheNode*> m_nodeHash; // <key, node>
    mutable unordered_map<int, DoublyLinkedList> m_dllistHash; // <frequency, doubly linked list>
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */