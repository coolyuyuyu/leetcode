class LFUCache {
public:
    LFUCache(int capacity)
        : m_capacity(capacity)
        , m_nodes(new Node[m_capacity])
        , m_minFreq(0) {
    }

    virtual ~LFUCache() {
        delete[] m_nodes;
    }

    int get(int key) {
        if (m_key2itr.find(key) == m_key2itr.end()) {
            return -1;
        }

        Node* node = *(m_key2itr[key]);

        m_freq2list[node->freq].erase(m_key2itr[key]);
        if (m_freq2list[node->freq].empty()) {
            m_freq2list.erase(node->freq);

            if (node->freq == m_minFreq) {
                ++m_minFreq;
            }
        }
        m_freq2list[++(node->freq)].push_back(node);

        m_key2itr[key] = std::prev(m_freq2list[node->freq].end());

        return node->val;
    }

    void put(int key, int value) {
        if (capacity() == 0) {
            return;
        }

        if (get(key) != -1) {
            (*(m_key2itr[key]))->val = value;
            return;
        }

        Node* node;
        if (capacity() <= size()) {
            node = m_freq2list[m_minFreq].front();
            m_freq2list[m_minFreq].pop_front();
            if (m_freq2list[m_minFreq].empty()) {
                m_freq2list.erase(m_minFreq);
            }

            m_key2itr.erase(node->key);
        }
        else {
            node = &(m_nodes[size()]);
        }

        node->key = key;
        node->val = value;
        node->freq = 0;

        m_minFreq = 0;
        m_freq2list[m_minFreq].push_back(node);
        m_key2itr[key] = std::prev(m_freq2list[m_minFreq].end());
    }

    size_t capacity() const {
        return m_capacity;
    }

    size_t size() const {
        return m_key2itr.size();
    }

private:
    class Node {
    public:
        int key;
        int val;
        int freq;
    };

    size_t m_capacity;
    Node* m_nodes;

    size_t m_minFreq;
    unordered_map<int, list<Node*>> m_freq2list;
    unordered_map<int, list<Node*>::iterator> m_key2itr;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
