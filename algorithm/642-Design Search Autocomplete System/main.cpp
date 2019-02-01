class AutocompleteSystem {
public:
    AutocompleteSystem(const vector<string>& sentences, const vector<int>& times) {
        size_t count = sentences.size();
        for (size_t i = 0; i < count; ++i) {
            m_trie.addSentence(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            m_trie.complete();
            return {};
        }

        m_trie.traverseDown(c);
        return m_trie.lookup(3);
    }

private:
    class Trie {
    public:
        Trie()
            : m_pRoot(new TrieNode())
            , m_ppNode(&m_pRoot){
        }

        ~Trie() {
            destruct(m_pRoot);
        }

        void addSentence(const string& sentence, size_t time) {
            TrieNode** ppNode = &m_pRoot;
            for (char c : sentence) {
                ppNode = &((*ppNode)->childs[TrieNode::index(c)]);
                if (*ppNode == nullptr) {
                    *ppNode = new TrieNode();
                }
            }

            (*ppNode)->time += time;
        }

        vector<string> lookup(size_t k) {
            string prefix;
            priority_queue<pair<size_t, string>, vector<pair<size_t, string>>, decltype(&comp)> pq(&comp);
            traverse(prefix, *m_ppNode, k, pq);

            vector<string> sentences(pq.size());
            for (size_t i = sentences.size(); 0 < i--;) {
                sentences[i] = m_inputs + pq.top().second;
                pq.pop();
            }
            return sentences;
        }

        void traverseDown(char c) {
            m_inputs.push_back(c);

            m_ppNode = &((*m_ppNode)->childs[TrieNode::index(c)]);
            if (*m_ppNode == nullptr) {
                *m_ppNode = new TrieNode();
            }
        }

        void complete() {
            (*m_ppNode)->time += 1;

            m_ppNode = &m_pRoot;
            m_inputs.clear();
        }

    private:
        class TrieNode {
        public:
            TrieNode()
                : time(0) {
            }

            static const size_t CHILD_COUNT = 27;
            inline static size_t index(char c) {
                return c == ' ' ? 26 : c - 'a';
            }

            TrieNode* childs[CHILD_COUNT] = {nullptr};
            size_t time;
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

        public:
        static bool comp(const pair<size_t, string>& a, const pair<size_t, string>& b) {
            if (b.first == a.first) {
                return a.second < b.second;
            }
            else {
                return b.first < a.first;
            }
        }

        template<class T>
        void traverse(string& prefix, TrieNode* pNode, size_t k, T& pq) {
            if (!pNode) {
                return;
            }

            if (0 < pNode->time) {
                if (pq.size() < k) {
                    pq.emplace(pNode->time, prefix);
                }
                else if (comp({pNode->time, prefix}, pq.top())) {

                    pq.pop();
                    pq.emplace(pNode->time, prefix);
                }
            }

            for (size_t i = 0; i < TrieNode::CHILD_COUNT; ++i) {
                prefix.push_back(i < (TrieNode::CHILD_COUNT - 1) ? 'a' + i : ' ');
                traverse(prefix, pNode->childs[i], k, pq);
                prefix.pop_back();
            }
        }

        TrieNode* m_pRoot;
        TrieNode** m_ppNode;
        string m_inputs;
    };

    Trie m_trie;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */