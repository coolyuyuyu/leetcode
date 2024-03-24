class Solution {
public:
    class TrieNode {
    public:
        array<TrieNode*, 26> childs;
        int len;
        int idx;

        TrieNode() {
            childs.fill(nullptr);
            len = INT_MAX;
        }
    };

    void add(TrieNode* root, int idx, const string& s) {
        TrieNode* node = root;
        if (s.size() < node->len) {
            node->len = s.size();
            node->idx = idx;
        }

        for (int i = s.size(); 0 < i--;) {
            if (node->childs[s[i] - 'a'] == nullptr) {
                node->childs[s[i] - 'a'] = new TrieNode();
            }
            node = node->childs[s[i] - 'a'];

            if (s.size() < node->len) {
                node->len = s.size();
                node->idx = idx;
            }
        }
    }

    int find(TrieNode* root, const string& s) {
        TrieNode* node = root;
        int ret = node->idx;

        for (int i = s.size(); 0 < i--;) {
            if (node->childs[s[i] - 'a'] == nullptr) {
                break;
            }
            node = node->childs[s[i] - 'a'];

            ret = node->idx;
        }

        return ret;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < wordsContainer.size(); ++i) {
            add(root, i, wordsContainer[i]);
        }

        vector<int> ret(wordsQuery.size());
        for (int i = 0; i < wordsQuery.size(); ++i) {
            ret[i] = find(root, wordsQuery[i]);
        }

        return ret;
    }
};
