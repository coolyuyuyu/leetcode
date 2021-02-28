class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }

        vector<int> ans;

        TrieNode* pRoot = constructTrie(words);
        size_t totalSize = words.size() * words.front().size();
        for (size_t i = 0; i + totalSize <= s.size(); ++i) {
            size_t pos = i;
            vector<TrieNode*> nodes;
            while (nodes.size() < words.size()) {
                TrieNode* pNode = searchTrieNode(pRoot, s, pos);
                if (pNode) {
                    --(pNode->count);
                    nodes.emplace_back(pNode);
                }
                else {
                    break;
                }
            }

            if (words.size() <= nodes.size()) {
                ans.emplace_back(i);
            }

            for (TrieNode* pNode : nodes) {
                ++(pNode->count);
            }
        }
        destructTrie(pRoot);

        return ans;
    }

private:
    class TrieNode {
    public:
        TrieNode()
            : count(0) {
            memset(childs, 0, sizeof(childs));
        }
        TrieNode* childs[26];
        size_t count;
    };

    TrieNode* constructTrie(const vector<string>& words) {
        TrieNode* pRoot = new TrieNode();
        for (const string& word : words) {
            TrieNode** ppNode = &pRoot;
            for (char c : word) {
                size_t index = c - 'a';
                ppNode = &((*ppNode)->childs[index]);
                if (*ppNode == nullptr) {
                    *ppNode = new TrieNode();
                }
            }
            ++((*ppNode)->count);
        }

        return pRoot;
    };

    void destructTrie(TrieNode* pRoot) {
        if (!pRoot) {
            return;
        }

        for (size_t i = 0; i < 26; ++i) {
            destructTrie(pRoot->childs[i]);
        }

        delete pRoot;
    }

    TrieNode* searchTrieNode(TrieNode* pRoot, const string& word, size_t& pos) {
        assert(pos < word.size());

        TrieNode* pNode = pRoot;
        while (pos < word.size() && pNode) {
            if (pNode->count) {
                break;
            }
            pNode = pNode->childs[word[pos++] - 'a'];
        }
        if (pNode && pNode->count == 0) {
            pNode = nullptr;
        }

        return pNode;
    }
};