class Trie {
public:
    struct Node {
        Node()
            : end(false) {
            childs.fill(nullptr);
        }

        array<Node*, 26> childs;
        bool end;
    };

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
        }
        node->end = true;
    }

    const Node* getRoot() const {
        return m_root;
    }

private:
    Node* m_root;
};

class Solution {
public:
    vector<vector<int>> bruteforce_search(string text, vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s, const string& t) { return s.size() < t.size(); });

        vector<vector<int>> ret;
        for (int i = 0; i < text.size(); ++i) {
            for (const string word : words) {
                if (text.compare(i, word.size(), word) == 0) {
                    ret.push_back({i, i + (int)word.size() - 1});
                }
            }
        }

        return ret;
    }

    vector<vector<int>> trie_search(string text, vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.addWord(word);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < text.size(); ++i) {
            const Trie::Node* node = trie.getRoot();
            for (int j = i; j < text.size() && node; ++j) {
                node = node->childs[text[j] - 'a'];
                if (node && node->end) {
                    ret.push_back({i, j});
                }
            }
        }

        return ret;
    }

    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        //return bruteforce_search(text, words);
        return trie_search(text, words);
    }
};
