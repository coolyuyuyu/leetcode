class Solution {
public:
    static bool checkPalindrome(const string& word, size_t first, size_t last) {
        assert(first < word.size() && last <= word.size());

        while (first + 1 < last) {
            if (word[first] != word[last - 1]) {
                return false;
            }
            ++first;
            --last;
        }

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.addWord(word);
        }

        vector<vector<int>> pairs;
        for (size_t i = 0; i < words.size(); ++i) {
            vector<size_t> indexes = trie.getPalindromeSuffixIndexes(words[i]);
            for (size_t index : indexes) {
                if (index != i) {
                    pairs.push_back({i, index});
                }
            }
        }
        return pairs;
    }

private:
    class Trie {
    public:
        Trie()
            : m_pRoot(new TrieNode())
            , m_count(0) {
        }

        ~Trie() {
            destruct(m_pRoot);
        }

        void addWord(const string& word) {
            size_t index = m_count++;

            TrieNode** ppNode = &m_pRoot;
            for (size_t i = word.size(); 0 < i--;) {
                if (checkPalindrome(word, 0, i + 1)) {
                    (*ppNode)->indexesPalindrome.emplace_back(index);
                }

                char c = word[i];
                ppNode = &((*ppNode)->childs[c - 'a']);
                if (*ppNode == nullptr) {
                    *ppNode = new TrieNode();
                }
            }

            (*ppNode)->indexes.emplace_back(index);
        }

        vector<size_t> getPalindromeSuffixIndexes(const string& word) {
            vector<size_t> indexes;

            TrieNode* pNode = m_pRoot;
            for (size_t i = 0; i < word.size(); ++i) {
                if (pNode->indexes.empty() == false) {
                    if (checkPalindrome(word, i, word.size())) {
                        indexes.insert(indexes.end(), pNode->indexes.begin(), pNode->indexes.end());
                    }
                }

                pNode = pNode->childs[word[i] - 'a'];
                if (pNode == nullptr) {
                    return indexes;
                }
            }

            indexes.insert(indexes.end(), pNode->indexes.begin(), pNode->indexes.end());
            indexes.insert(indexes.end(), pNode->indexesPalindrome.begin(), pNode->indexesPalindrome.end());

            return indexes;
        }

    private:
        class TrieNode {
        public:
            static const size_t CHILD_COUNT = 26;

            TrieNode* childs[CHILD_COUNT] = {nullptr};
            vector<size_t> indexes;
            vector<size_t> indexesPalindrome;
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

        TrieNode* m_pRoot;
        size_t m_count;
    };
};