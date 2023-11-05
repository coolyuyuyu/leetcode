class MyHashMap {
public:
    MyHashMap(size_t n = 101)
        : m_size(0)
        , m_buckets(n) {
    }

    void put(int key, int value) {
        for (auto& [k, v] : m_buckets[hash(key)]) {
            if (k == key) {
                v = value;
                return;
            }
        }

        if ((m_size + 1) / m_buckets.size() >= s_threshold) {
            rehash(m_size * s_growfactor);
        }

        m_buckets[hash(key)].emplace_front(key, value);
        ++m_size;
    }

    int get(int key) {
        for (auto& [k, v] : m_buckets[hash(key)]) {
            if (k == key) {
                return v;
            }
        }

        return -1;
    }

    void remove(int key) {
        auto& bucket = m_buckets[hash(key)];
        for (auto pre = bucket.before_begin(), cur = bucket.begin(); cur != bucket.end(); ++pre, ++cur) {
            if (cur->first == key) {
                bucket.erase_after(pre);
                --m_size;
                break;
            }
        }
    }

private:
    static const double s_threshold;
    static const double s_growfactor;

    size_t hash(int key) {
        return key % m_buckets.size();
    }

    void rehash(size_t n) {
        vector<forward_list<pair<const int, int>>> buckets = std::move(m_buckets);

        m_buckets.resize(n);
        for (const forward_list<pair<const int, int>>& bucket : buckets) {
            for (const auto& [k, v] : bucket) {
                m_buckets[hash(k)].emplace_front(k, v);
            }
        }
    }

    size_t m_size;
    vector<forward_list<pair<const int, int>>> m_buckets;
};

const double MyHashMap::s_threshold = 1.5f;
const double MyHashMap::s_growfactor = 0.75f;

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
