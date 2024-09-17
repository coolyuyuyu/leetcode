class StreamChecker {
private:
    struct Node {
        array<Node*, 26> childs;
        Node* fail;
        bool sufend;
        Node() {
            childs.fill(nullptr);
            fail = nullptr;
            sufend = false;
        }
    };

    Node* m_root;
    Node* m_node;
    unordered_map<Node*, bool> m_cache;

public:
    StreamChecker(vector<string>& words) {
        m_root = new Node();
        for (const string& word : words) {
            Node* node = m_root;
            for (char c : word) {
                int v = c - 'a';
                if (node->childs[v] == nullptr) {
                    node->childs[v] = new Node();
                }
                node = node->childs[v];
            }
            node->sufend = true;
        }

        // build fail link
        for (queue<Node*> q({m_root}); !q.empty();) {
            Node* u = q.front();
            q.pop();

            for (int i = 0; i < 26; ++i) {
                Node* v = u->childs[i];
                if (!v) { continue; }
                if (u == m_root) {
                    v->fail = m_root;
                }
                else {
                    Node* node = u->fail;
                    while (node != m_root && node->childs[i] == nullptr) {
                        node = node->fail;
                    }
                    v->fail = node->childs[i] ? node->childs[i] : m_root;
                }
                v->sufend |= v->fail->sufend;

                q.push(v);
            }
        }

        m_node = m_root;
    }

    bool query(char letter) {
        int v = letter - 'a';
        while (m_node != m_root && m_node->childs[v] == nullptr) {
            m_node = m_node->fail;
        }
        if (m_node->childs[v]) {
            m_node = m_node->childs[v];
        }

        return m_node->sufend;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
