class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            if (word.empty()) {
                continue;
            }
            trie.addWord(word);
        }

        vector<string> results;
        for (const string& word : words) {
            if (word.empty()) {
                continue;
            }

            trie.removeWord(word);
            if (trie.checkBreakable(word)) {
                results.emplace_back(word);
            }
            trie.addWord(word);
        }
        return results;
    }

private:
    class Trie {
    public:
        Trie()
            : m_pRoot(new TrieNode()) {
        }

        ~Trie() {
            destruct(m_pRoot);
        }

        void addWord(const string& word) {
            assert(!word.empty());

            TrieNode** ppNode = &m_pRoot;
            for (char c : word) {
                ppNode = &((*ppNode)->childs[c - 'a']);
                if (*ppNode == nullptr) {
                    *ppNode = new TrieNode();
                }
            }

            (*ppNode)->end = true;
        }

        void removeWord(const string& word) {
            TrieNode* pNode = m_pRoot;
            for (char c : word) {
                pNode = pNode->childs[c - 'a'];
                if (!pNode) {
                    return;
                }
            }

            pNode->end = false;
        }

        bool checkBreakable(const string& word) {
            assert(!word.empty());

            bool dones[word.size()];
            memset(dones, false, sizeof(bool) * word.size());
            bool breakables[word.size()];
            memset(breakables, 0, sizeof(bool) * word.size());

            return checkBreakable(word, 0, dones, breakables);
        }

    private:
        class TrieNode {
        public:
            static const size_t CHILD_COUNT = 26;
            TrieNode* childs[CHILD_COUNT] = {nullptr};
            bool end = false;
        };

        void destruct(TrieNode* pRoot) {
            if (!pRoot) {
                return;
            }

            for (size_t i = 0; i < TrieNode::CHILD_COUNT; ++i) {
                destruct(pRoot->childs[i]);
            }
            delete pRoot;
        }

        bool checkBreakable(const string& word, size_t index, bool dones[], bool breakables[]) {
            assert(index < word.size());

            if (dones[index]) {
                return breakables[index];
            }

            bool breakable = false;
            TrieNode* pNode = m_pRoot;
            for (size_t i = index; i < word.size() && !breakable; ++i) {
                char c = word[i];
                pNode = pNode->childs[c - 'a'];
                if (!pNode) {
                    break;
                }

                if (pNode->end) {
                    if (i + 1 < word.size()) {
                        breakable = checkBreakable(word, i + 1, dones, breakables);
                    }
                    else {
                        breakable = true;
                    }
                }

            }

            dones[index] = true;
            breakables[index] = breakable;

            return breakable;
        }

        TrieNode* m_pRoot;
    };
};