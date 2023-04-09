class Trie {
public:
    Trie()
        : m_root(new Node()) {
    }

    void addWord(const string& word) {
        Node* node = m_root;
        for (char c : word) {
            if (node->childs[c - 'a'] == nullptr) {
                node->childs[c - 'a'] = new Node();
            }
            node = node->childs[c - 'a'];
            node->count += 1;
        }
    }

    int score(const string& word) {
        int s = 0;
        Node* node = m_root;
        for (char c : word) {
            if (node->childs[c - 'a'] == nullptr) {
                node->childs[c - 'a'] = new Node();
            }
            node = node->childs[c - 'a'];
            s += node->count;
        }

        return s;
    }

private:
    class Node {
    public:
        Node()
            : count(0) {
            childs.fill(nullptr);
        }

        array<Node*, 26> childs;
        int count;
    };

    Node* m_root;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.addWord(word);
        }

        size_t n = words.size();

        vector<int> ret(n);
        for (size_t i = 0; i < n; ++i) {
            ret[i] = trie.score(words[i]);
        }

        return ret;
    }
};
