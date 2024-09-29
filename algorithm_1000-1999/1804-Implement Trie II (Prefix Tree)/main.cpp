class Trie {
private:
    struct Node {
        int preCnt;
        int cnt;
        array<Node*, 26> childs;
        Node() {
            preCnt = 0;
            cnt = 0;
            childs.fill(nullptr);
        }
    };
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
            node->preCnt += 1;
        }
        node->cnt += 1;
    }

    int countWordsEqualTo(string word) {
        Node* node = getNode(word);
        return node ? node->cnt : 0;
    }

    int countWordsStartingWith(string prefix) {
        Node* node = getNode(prefix);
        return node ? node->preCnt : 0;
    }

    void erase(string word) {
        Node* node = m_root;
        for (char c : word) {
            node = node->childs[c - 'a'];
            node->preCnt -= 1;
        }
        node->cnt -= 1;
    }

private:
    Node* getNode(const string& s) {
        Node* node = m_root;
        for (int i = 0; i < s.size() && node; ++i) {
            node = node->childs[s[i] - 'a'];
        }
        return node;
    }

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
