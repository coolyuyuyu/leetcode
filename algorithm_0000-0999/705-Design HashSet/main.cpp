class MyHashSet {
public:
    MyHashSet()
        : m_size(0)
        , m_bucketCnt(0)
        , m_buckets(nullptr)
        , m_hasher([&](int key) { return key % bucket_count(); })
        , m_maxLoadFactor(0.8f) {
    }

    void add(int key) {
        if (bucket_count() == 0) {
            rehash(11);
        }

        Node** ppNode = find(key);
        if (*ppNode == nullptr) {
            ++m_size;

            *ppNode = new Node(key);

            if (max_load_factor() <= load_factor()) {
                rehash(bucket_count() * 2);
            }
        }
    }

    void remove(int key) {
        Node** ppNode = find(key);
        if (ppNode && *ppNode) {
            --m_size;

            Node* pDel = *ppNode;
            *ppNode = pDel->next;
            delete pDel;
        }
    }

    bool contains(int key) {
        Node** ppNode = find(key);
        return ppNode && *ppNode;
    }

    size_t size() const {
        return m_size;
    }

    bool empty() const {
        return size() == 0;
    }

    size_t bucket_count() const {
        return m_bucketCnt;
    }

    float load_factor() const {
        return static_cast<float>(size()) / bucket_count();
    }

    float max_load_factor() const {
        return m_maxLoadFactor;
    }

private:
    struct Node {
        Node(int val_)
            : val(val_)
            , next(nullptr) {
        }

        int val;
        Node* next;
    };

    Node** find(int key) const {
        if (bucket_count() == 0) {
            return nullptr;
        }

        Node** ppNode = &(m_buckets[m_hasher(key)]);
        for (; *ppNode; ppNode = &((*ppNode)->next)) {
            if ((*ppNode)->val == key) {
                break;
            }
        }

        return ppNode;
    }

    void rehash(size_t n) {
        size_t bucketCnt = m_bucketCnt;
        m_bucketCnt = floorPrime(n);

        Node** buckets = m_buckets;
        m_buckets = new Node* [m_bucketCnt]();
        for (size_t i = 0; i < bucketCnt; ++i) {
            while (buckets[i]) {
                Node* pNode = buckets[i];
                buckets[i] = pNode->next;

                Node** pHead = &(m_buckets[m_hasher(pNode->val)]);
                pNode->next = *pHead;
                *pHead = pNode;
            }
        }

        delete [] buckets;
    }

    int floorPrime(int n)
    {
        static constexpr int s_primes[11] = {11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421, 12847};
        return *std::upper_bound(s_primes, s_primes + 11, n);
    }

    size_t m_size;
    size_t m_bucketCnt;
    Node** m_buckets;

    std::function<size_t(int)> m_hasher;
    float m_maxLoadFactor;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
