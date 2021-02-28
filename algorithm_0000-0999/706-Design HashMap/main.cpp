class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap(int capacity = 101)
        : m_size(0)
        , m_capacity(capacity) {
        m_buckets = new ListNode*[m_capacity];
        memset(m_buckets, 0, sizeof(ListNode*) * m_capacity);
    }

    ~MyHashMap() {
        for (size_t i = 0; i < m_capacity; ++i) {
            ListNode* pNode = m_buckets[i];
            while (pNode) {
                ListNode* pDel = pNode;
                pNode = pNode->pNext;
                delete pDel;
            }
        }

        delete[] m_buckets;
    }

    /** value will always be non-negative. */
    void put(int key, int val) {
        size_t index = hash(key);
        for (ListNode* pNode = m_buckets[index]; pNode; pNode = pNode->pNext) {
            if (pNode->key == key) {
                pNode->val = val;
                return;
            }
        }

        if ((double)m_size / m_capacity >= s_threshold) {
            rehash((double)m_capacity * s_growFactor);
        }

        ListNode *pNode = new ListNode(key, val);
        index = hash(key);
        ListNode** ppHead = &(m_buckets[index]);
        pNode->pNext = *ppHead;
        *ppHead = pNode;

        ++m_size;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        size_t index = hash(key);
        for (ListNode* pNode = m_buckets[index]; pNode; pNode = pNode->pNext) {
            if (pNode->key == key) {
                return pNode->val;
            }
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        size_t index = hash(key);
        ListNode** ppNode = &(m_buckets[index]);

        while (*ppNode) {
            if ((*ppNode)->key == key) {
                *ppNode = (*ppNode)->pNext;
                --m_size;

                break;
            }
            ppNode = &((*ppNode)->pNext);
        }
    }

private:
    class ListNode {
    public:
        ListNode(int key_, int val_)
            : key(key_)
            , val(val_)
            , pNext(nullptr) {
        }
        int key;
        int val;
        ListNode* pNext;
    };

    size_t hash(int key) {
        return key % m_capacity;
    }

    void rehash(size_t capacity) {
        ListNode** buckets = m_buckets;
        swap(m_capacity, capacity);

        m_buckets = new ListNode*[m_capacity];
        memset(m_buckets, 0, sizeof(ListNode*) * m_capacity);

        for (size_t i = 0; i < capacity; ++i) {
            ListNode* pNode = buckets[i];
            while (pNode) {
                ListNode* pMove = pNode;
                pNode = pNode->pNext;

                size_t index = hash(pMove->key);
                ListNode** ppHead = &(m_buckets[index]);
                pMove->pNext = *ppHead;
                *ppHead = pMove;
            }
        }
        delete[] buckets;
    }

    static const double s_growFactor;
    static const double s_threshold;

    size_t m_size;
    size_t m_capacity;
    ListNode** m_buckets;
};

const double MyHashMap::s_growFactor = 1.5f;
const double MyHashMap::s_threshold = 0.75f;

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
