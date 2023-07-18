class LRUCache {
public:
    LRUCache(int capacity)
        : m_capacity(capacity)
        , m_nodes(new Node[m_capacity]) {
    }

    virtual ~LRUCache() {
        delete[] m_nodes;
    }

    int get(int key) {
        if (m_key2itr.find(key) == m_key2itr.end()) {
            return -1;
        }

        auto itr = m_key2itr[key];
        Node* node = *itr;
        m_list.erase(itr);
        m_list.push_back(node);
        m_key2itr[key] = std::prev(m_list.end());

        return node->val;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            (*m_key2itr[key])->val = value;
            return;
        }

        Node* node = nullptr;
        if (size() < capacity()) {
            node = m_nodes + m_key2itr.size();
        }
        else {
            node = m_list.front();
            m_list.pop_front();
            m_key2itr.erase(node->key);
        }

        node->key = key;
        node->val = value;
        m_list.push_back(node);
        m_key2itr[key] = std::prev(m_list.end());
    }

    int capacity() const {
        return m_capacity;
    }

    int size() const {
        return m_key2itr.size();
    }

private:
    struct Node {
        int key;
        int val;
    };

    int m_capacity;
    Node* m_nodes;

    list<Node*> m_list;
    unordered_map<int, list<Node*>::iterator> m_key2itr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
