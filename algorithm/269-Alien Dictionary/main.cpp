class Solution {
public:
    class Trie {
    public:
        Trie()
            : m_pRoot(new TrieNode()) {
        }

        ~Trie() {
            assert(m_pRoot);
            destruct(m_pRoot);
        }

        void addWord(const string& word) {
            TrieNode* pNode = m_pRoot;
            for (char c : word) {
                size_t index = c - 'a';
                if (pNode->m_childs[index] == nullptr) {
                    pNode->m_childs[index] = new TrieNode();
                }

                m_adjLists.emplace(c, unordered_set<char>());
                for (size_t i = 0; i < TrieNode::CHILD_COUNT; ++i) {
                    if (pNode->m_childs[i] == nullptr || i == index) {
                        continue;
                    }
                    m_adjLists[char('a' + i)].emplace(c);
                }

                pNode = pNode->m_childs[index];
            }
        }

        unordered_map<char, unordered_set<char>>& getAdjLists() {
            return m_adjLists;
        }

    private:
        class TrieNode {
        public:
            TrieNode() {
            }

            static const size_t CHILD_COUNT = 26;
            TrieNode* m_childs[CHILD_COUNT] = {nullptr};
        };

        void destruct(TrieNode* root) {
            if (root) {
                for (size_t i = 0; i < TrieNode::CHILD_COUNT; ++i) {
                    if (root->m_childs[i]) {
                        destruct(root->m_childs[i]);
                    }
                }

                delete root;
            }
        }

        TrieNode* m_pRoot;
        unordered_map<char, unordered_set<char>> m_adjLists;
    };

    string alienOrder(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.addWord(word);
        }
        unordered_map<char, unordered_set<char>>& adjLists = trie.getAdjLists();

        unordered_map<char, int> inCounts;
        for (auto p : adjLists) {
            const unordered_set<char>& adjList = p.second;
            inCounts.emplace(p.first, 0);
            for (char neighbor : adjList) {
                ++inCounts[neighbor];
            }
        }

        string letters;
        queue<char> q;
        for (auto p : inCounts) {
            if (p.second == 0) {
                q.emplace(p.first);
            }
        }
        while (!q.empty()) {
            char c = q.front();
            q.pop();

            letters.push_back(c);
            for (char neighbor : adjLists[c]) {
                if (--inCounts[neighbor] == 0) {
                    q.emplace(neighbor);
                }
            }
        }

        return letters.size() == adjLists.size() ? letters : "";
    }
};