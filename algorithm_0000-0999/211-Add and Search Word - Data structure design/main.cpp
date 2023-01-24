class WordDictionary {
private:
    class TrieNode {
    public:
        TrieNode()
            : end(false) {
            childs.fill(nullptr);
        }

        bool end;
        array<TrieNode*, 26> childs;
    };

public:
    WordDictionary()
        : m_pRoot(new TrieNode()) {
    }

    void addWord(string word) {
        TrieNode** ppNode = &m_pRoot;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode();
            }
        }

        (*ppNode)->end = true;
    }

    bool search(const string& word) {
        return search(word, 0, m_pRoot);
    }

private:
    bool search(const string& word, size_t start, TrieNode* pNode) {
        for (size_t i = start; i < word.size() && pNode; ++i) {
            if (word[i] == '.') {
                return std::any_of(
                    pNode->childs.begin(),
                    pNode->childs.end(),
                    [&](TrieNode* pChild) { return pChild && search(word, i + 1, pChild); });
            }
            else {
                pNode = pNode->childs[word[i] - 'a'];
            }
        }

        return pNode && pNode->end;
    }

    TrieNode* m_pRoot;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
