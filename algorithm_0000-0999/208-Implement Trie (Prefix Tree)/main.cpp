class Trie {
public:
    Trie() 
        : m_root(new Node) {
    }
    
    void insert(string word) {
        Node** ppNode = &m_root;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new Node;
            }
        }
        (*ppNode)->end = true;
    }
    
    bool search(string word) {
        Node* node = m_root;
        for (size_t i = 0; i < word.size() && node; ++i) {
            node = node->childs[word[i] - 'a'];
        }

        return node && node->end;
    }
    
    bool startsWith(string prefix) {
        Node* node = m_root;
        for (size_t i = 0; i < prefix.size() && node; ++i) {
            node = node->childs[prefix[i] - 'a'];
        }

        return node;
    }

private:
    class Node {
    public:
        Node() {
            std::fill(childs.begin(), childs.end(), nullptr);
            end = false;
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
