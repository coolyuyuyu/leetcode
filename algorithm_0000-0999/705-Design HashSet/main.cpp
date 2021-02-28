class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet(int capacity = 101)
        : m_size(0)
        , m_capacity(capacity) {
        m_buckets = new ListNode* [m_capacity];
        memset(m_buckets, 0, sizeof(ListNode*) * m_capacity);
    }

    ~MyHashSet() {
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

    void add(int key) {
        if (contains(key)) {
            return;
        }

        if ((double)m_size / m_capacity >= s_threshold) {
            rehash((double)m_capacity * s_growFactor);
        }

        ListNode *pNode = new ListNode(key);

        size_t index = hash(key);
        ListNode** ppHead = &(m_buckets[index]);
        pNode->pNext = *ppHead;
        *ppHead = pNode;

        ++m_size;
    }

    void remove(int key) {
        size_t index = hash(key);
        ListNode** ppNode = &(m_buckets[index]);

        while (*ppNode) {
            if ((*ppNode)->val == key) {
                *ppNode = (*ppNode)->pNext;
                --m_size;

                break;
            }
            ppNode = &((*ppNode)->pNext);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        size_t index = hash(key);
        for (ListNode* pNode = m_buckets[index]; pNode; pNode = pNode->pNext) {
            if (pNode->val == key) {
                return true;
            }
        }

        return false;
    }

private:
    class ListNode {
    public:
        ListNode(int val_)
            : val(val_)
            , pNext(nullptr) {
        }
        int val;
        ListNode* pNext;
    };

    size_t hash(int val) {
        return val % m_capacity;
    }

    void rehash(size_t capacity) {
        ListNode** buckets = m_buckets;
        swap(m_capacity, capacity);

        m_buckets = new ListNode* [m_capacity];
        memset(m_buckets, 0, sizeof(ListNode*) * m_capacity);

        for (size_t i = 0; i < capacity; ++i) {
            ListNode* pNode = buckets[i];
            while (pNode) {
                ListNode* pMove = pNode;
                pNode = pNode->pNext;

                size_t index = hash(pMove->val);
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

const double MyHashSet::s_growFactor = 1.5f;
const double MyHashSet::s_threshold = 0.75f;

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */