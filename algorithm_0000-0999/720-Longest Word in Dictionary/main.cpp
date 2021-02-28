class Solution {
public:
    class TrieNode {
    public:
        static const int childSize = 26;

        TrieNode* childs[childSize] = {nullptr};
        bool end = false;
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode;
        root->end = true;

        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (node->childs[index] == nullptr) {
                    node->childs[index] = new TrieNode;
                }
                node = node->childs[index];
            }
            node->end = true;
        }

        return root;
    }

    void longestWordDfs(TrieNode* node, string& currentWord, string& longestWord) {
        assert(node);

        for (int i = 0; i < TrieNode::childSize; ++i) {
            if (node->childs[i]) {
                TrieNode* child = node->childs[i];
                if (child->end) {
                    currentWord.push_back('a' + i);
                    if (longestWord.size() < currentWord.size()) {
                        longestWord = currentWord;
                    }
                    longestWordDfs(child, currentWord, longestWord);
                    currentWord.pop_back();
                }
            }
        }
    }

    string longestWord(vector<string>& words) {
        assert(!words.empty());

        TrieNode* root = buildTrie(words);
        string currentWord, longestWord;
        longestWordDfs(root, currentWord, longestWord);
        return longestWord;
    }
};
