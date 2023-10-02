class Trie {
public:
    Trie()
        : m_root(new Node()) {
    }

    void insert(string word) {
        Node* node = m_root;
        for (char c : word) {
            if (node->childs[c - 'a'] == nullptr) {
                node->childs[c - 'a'] = new Node();
            }
            node = node->childs[c - 'a'];
            node->prefixCnt += 1;
        }
        node->cnt += 1;
    }

    int countWordsEqualTo(string word) {
        Node* node = m_root;
        for (char c : word) {
            if (node->childs[c - 'a'] == nullptr) {
                return 0;
            }
            node = node->childs[c - 'a'];
        }
        return node->cnt;
    }

    int countWordsStartingWith(string prefix) {
        Node* node = m_root;
        for (char c : prefix) {
            if (node->childs[c - 'a'] == nullptr) {
                return 0;
            }
            node = node->childs[c - 'a'];
        }
        return node->prefixCnt;
    }

    void erase(string word) {
        Node* node = m_root;
        for (char c : word) {
            node = node->childs[c - 'a'];
            node->prefixCnt -= 1;
        }
        node->cnt -= 1;
    }

private:
    struct Node {
        array<Node*, 26> childs;
        int prefixCnt = 0;
        int cnt = 0;

        Node()
            : prefixCnt(0)
            , cnt(0) {
            childs.fill(nullptr);
        }
    };

    Node* m_root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
