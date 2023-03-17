class Trie {
public:
    Trie()
        : m_root(new Node()) {
    }

    void insert(const string& word) {
        Node* node = m_root;
        for (char c : word) {
            if (node->childs[c - 'a'] == nullptr) {
                node->childs[c - 'a'] = new Node();
            }
            node = node->childs[c - 'a'];
        }
        node->end = true;
    }

    bool search(const string& word) {
        Node* node = m_root;
        for (char c : word) {
            if (node->childs[c - 'a'] == nullptr) {
                return false;
            }
            node = node->childs[c - 'a'];
        }

        return node->end;
    }

    bool startsWith(const string& prefix) {
        Node* node = m_root;
        for (char c : prefix) {
            if (node->childs[c - 'a'] == nullptr) {
                return false;
            }
            node = node->childs[c - 'a'];
        }

        return node;
    }

private:
    struct Node {
        Node()
            : end(false) {
            childs.fill(nullptr);
        }
        array<Node*, 26> childs;
        bool end;
    };

    Node* m_root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
