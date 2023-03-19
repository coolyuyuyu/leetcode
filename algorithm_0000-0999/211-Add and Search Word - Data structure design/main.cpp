class WordDictionary {
public:
    WordDictionary()
        : m_root(new Node()) {
    }

    void addWord(const string& word) {
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
        return search(word, 0, m_root);
    }

private:
    struct Node {
        Node() {
            childs.fill(nullptr);
            end = false;
        }

        array<Node*, 26> childs;
        bool end;
    };

    bool search(const string& word, size_t start, Node* node) {
        for (size_t i = start; i < word.size() && node; ++i) {
            if (word[i] == '.') {
                return std::any_of(
                    node->childs.begin(),
                    node->childs.end(),
                    [&](Node* child) { return child && search(word, i + 1, child); });
            }
            else {
                node = node->childs[word[i] - 'a'];
            }
        }

        return node && node->end;
    }

    Node* m_root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
