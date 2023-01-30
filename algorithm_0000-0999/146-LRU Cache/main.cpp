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

        Node* node = *(m_key2itr[key]);

        m_list.erase(m_key2itr[key]);
        m_list.push_back(node);

        m_key2itr[key] = std::prev(m_list.end());

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
            node = m_list.front();
            m_list.pop_front();

            m_key2itr.erase(node->key);
        }
        else {
            node = &(m_nodes[size()]);
        }

        node->key = key;
        node->val = value;

        m_list.push_back(node);
        m_key2itr[key] = std::prev(m_list.end());
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
    };

    size_t m_capacity;
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
