class WordFilter {
public:
    WordFilter(const vector<string>& words) {
        for (size_t i = 0; i < words.size(); ++i) {
            m_trieForward.addWord(words[i], i);

            string word = words[i];
            reverse(word.begin(), word.end());
            m_trieBackward.addWord(word, i);
        }
    }

    int f(const string& prefix, const string& suffix) {
        const vector<size_t>& candidatesForward = m_trieForward.search(prefix);

        string suf = suffix;
        reverse(suf.begin(), suf.end());
        const vector<size_t>& candidatesBackwrod = m_trieBackward.search(suf);

        for (auto first1 = candidatesForward.rbegin(), last1 = candidatesForward.rend(), first2 = candidatesBackwrod.rbegin(), last2 = candidatesBackwrod.rend(); first1 != last1 && first2 != last2;) {
            if (*first1 < *first2) {
                ++first2;
            }
            else if (*first2 < *first1) {
                ++first1;
            }
            else {
                return *first1;
            }
        }

        return -1;
    }

private:
    class Trie {
    public:
        Trie()
            : m_pRoot(new TrieNode()) {
        }

        ~Trie() {
            assert(m_pRoot);
            destruct(m_pRoot);
        }

        void addWord(const string& word, size_t weight) {
            TrieNode** ppNode = &m_pRoot;
            for (char c : word) {
                (*ppNode)->m_weights.emplace_back(weight);

                ppNode = &((*ppNode)->m_childs[c - 'a']);
                if (*ppNode == nullptr) {
                    *ppNode = new TrieNode();
                }
            }

            (*ppNode)->m_weights.emplace_back(weight);
        }

        const vector<size_t>& search(const string& prefix) const {
            TrieNode* pNode = m_pRoot;
            for (char c : prefix) {
                pNode = pNode->m_childs[c - 'a'];
                if (!pNode) {
                    static vector<size_t> EMPTY_WEIGHTS(0);
                    return EMPTY_WEIGHTS;
                }
            }

            return pNode->m_weights;
        }

    private:
        class TrieNode {
        public:
            TrieNode() {
            }

            static const size_t CHILD_COUNT = 26;
            TrieNode* m_childs[CHILD_COUNT] = {nullptr};
            vector<size_t> m_weights;
        };

        void destruct(TrieNode* pRoot) {
            if (!pRoot) {
                return;
            }

            for (size_t i = 0; i < TrieNode::CHILD_COUNT; ++i) {
                if (pRoot->m_childs[i]) {
                    destruct(pRoot->m_childs[i]);
                }
            }
            delete pRoot;
        }

        TrieNode* m_pRoot;
    };

    Trie m_trieForward;
    Trie m_trieBackward;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */