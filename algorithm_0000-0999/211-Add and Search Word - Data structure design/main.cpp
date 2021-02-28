class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary()
        : m_pRoot(new TrieNode()) {
    }

    /** Adds a word into the data structure. */
    void addWord(const string& word) {
        TrieNode** ppNode = &m_pRoot;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode();
            }
        }

        (*ppNode)->end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string& word) {
        return search(word, 0, m_pRoot);
    }

private:
    class TrieNode {
    public:
        TrieNode()
            : childs(26, nullptr)
            , end(false) {
        }

        vector<TrieNode*> childs;
        bool end;
    };

    bool search(const string& word, size_t index, TrieNode* pRoot) {
        if (!pRoot) {
            return false;
        }

        if (word.size() <= index) {
            return pRoot->end;
        }

        char c = word[index];
        if (c == '.') {
            for (TrieNode* pChild : pRoot->childs) {
                if (search(word, index + 1, pChild)) {
                    return true;
                }
            }

            return false;
        }
        else {
            return search(word, index + 1, pRoot->childs[c - 'a']);
        }
    }

    TrieNode* m_pRoot;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */