class LRUCache {
public:
    LRUCache(size_t capacity)
        : m_capacity(capacity)
        , m_size(0)
        , m_nodes(new CacheNode[m_capacity])
        , m_pHead(new CacheNode())
        , m_pTail(new CacheNode()) {
        m_pHead->pNext = m_pTail;
        m_pTail->pPrev = m_pHead;
    }

    ~LRUCache() {
        delete[] m_nodes;
        delete m_pHead;
        delete m_pTail;
    }

    int get(int key) const {
        CacheNode* pNode = nullptr; {
            auto itr = m_hash.find(key);
            if (itr != m_hash.end()) {
                pNode = itr->second;
            }
        }
        if (pNode) {
            const_cast<LRUCache*>(this)->detach(pNode);
            const_cast<LRUCache*>(this)->attach(pNode);
            return pNode->val;
        }
        else {
            return -1;
        }
    }

    void put(int key, int val) {
        if (m_capacity == 0) {
            return;
        }

        CacheNode* pNode = nullptr; {
            auto itr = m_hash.find(key);
            if (itr != m_hash.end()) {
                pNode = itr->second;
            }
        }
        if (pNode) {
            pNode->val = val;
            detach(pNode);
        }
        else {
            if (m_size < m_capacity) {
                pNode = m_nodes + m_size;
                ++m_size;
            }
            else {
                pNode = m_pTail->pPrev;
                m_hash.erase(pNode->key);
                detach(pNode);
            }

            pNode->key = key;
            pNode->val = val;

            m_hash[key] = pNode;
        }
        attach(pNode);
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

        int key;
        int val;

        CacheNode* pNext;
        CacheNode* pPrev;
    };

    void attach(CacheNode* pNode) {
        m_pHead->pNext->pPrev = pNode;
        pNode->pNext = m_pHead->pNext;
        m_pHead->pNext = pNode;
        pNode->pPrev = m_pHead;
    }

    void detach(CacheNode* pNode) {
        assert(pNode && pNode->pNext && pNode->pPrev);
        pNode->pNext->pPrev = pNode->pPrev;
        pNode->pPrev->pNext = pNode->pNext;
    }

    size_t m_capacity;
    size_t m_size;

    CacheNode* m_nodes;
    unordered_map<int, CacheNode*> m_hash;
    CacheNode* m_pHead;
    CacheNode* m_pTail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */