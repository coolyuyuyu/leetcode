class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary()
        : m_pRoot(new TrieNode()) {
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const string& word : dict) {
            insert(word);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return search(word, 0, false, m_pRoot);
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

    void insert(const string& word) {
        TrieNode** ppNode = &m_pRoot;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode();
            }
        }

        (*ppNode)->end = true;
    }

    bool search(const string& word, size_t index, bool modified, TrieNode* pRoot) {
        if (!pRoot) {
            return false;
        }

        if (word.size() <= index) {
            return pRoot->end && modified;
        }

        for (size_t i = 0; i < 26; ++i) {
            TrieNode* pChild = pRoot->childs[i];
            if (modified) {
                if ('a' + i == word[index]) {
                    if (search(word, index + 1, true, pChild)) {
                        return true;
                    }
                }
            }
            else {
                if (search(word, index + 1, ('a' + i != word[index]), pChild)) {
                    return true;
                }
            }
        }

        return false;
    }

    TrieNode* m_pRoot;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */