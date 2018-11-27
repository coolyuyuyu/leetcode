class Trie {
public:
    /** Initialize your data structure here. */
    Trie()
        : m_root(new TrieNode(false)) {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode** ppNode = &m_root;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode(false);
            }
        }

        (*ppNode)->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode** ppNode = &m_root;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                return false;
            }
        }

        return (*ppNode)->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode** ppNode = &m_root;
        for (char c : prefix) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                return false;
            }
        }

        return true;
    }

private:
    class TrieNode {
    public:
        TrieNode(bool end_)
            : end(end_)
            , childs(26, nullptr) {
        }
        bool end;
        vector<TrieNode*> childs;
    };

    TrieNode* m_root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */