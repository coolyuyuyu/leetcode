class Trie {
public:
    Trie(const vector<string>& words)
        : m_root(new Node)
        , m_success(true) {
        for (const string& word : words) {
            addWord(word);
        }
    }

    virtual ~Trie() {
        queue<Node*> q({m_root});
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            for (Node* child : node->m_childs) {
                if (child) {
                    q.push(child);
                }
            }

            delete node;
        }
    }

    void addWord(const string& word) {
        if (!m_success) {
            return;
        }

        Node* node = m_root;
        for (char c : word) {
            if (node->m_last != c && node->m_childs[c - 'a']) {
                m_success = false;
                return;
            }

            if (node->m_childs[c - 'a'] == nullptr) {
                node->m_childs[c - 'a'] = new Node();

                if (node->m_last) {
                    m_adjLists[node->m_last].insert(c);
                }
            }

            node->m_last = c;
            node = node->m_childs[c - 'a'];
        }

        if (std::any_of(node->m_childs.begin(), node->m_childs.end(), [](Node* node) { return node != nullptr; })) {
            m_success = false;
        }
    }

    const unordered_map<char, unordered_set<char>>& getAdjLists(bool& success) {
        success = m_success;
        return m_adjLists;
    }

private:
    struct Node {
        Node() {
            m_childs.fill(nullptr);
            m_last = '\0';
        }

        array<Node*, 26> m_childs;
        char m_last;
    };

    Node* m_root;
    bool m_success;
    unordered_map<char, unordered_set<char>> m_adjLists;
};

class Solution {
public:
    unordered_map<char, unordered_set<char>> constructGraphByStrComp(const vector<string>& words, bool& success) {
        unordered_map<char, unordered_set<char>> adjLists;
        for (size_t i = 1; i < words.size(); ++i) {
            const string& s = words[i - 1];
            const string& t = words[i];

            int j = 0, n = std::min(s.size(), t.size());
            for (; j < n; ++j) {
                if (s[j] != t[j]) {
                    adjLists[s[j]].insert(t[j]);
                    break;
                }
            }
            if (j == n && t.size() < s.size()) {
                success = false;
                return {};
            }
        }

        success = true;
        return adjLists;
    }

    unordered_map<char, unordered_set<char>> constructGraphByTrie(const vector<string>& words, bool& success) {
        unordered_map<char, unordered_set<char>> adjLists = Trie(words).getAdjLists(success);
        return adjLists;
    }

    string alienOrder(vector<string>& words) {
        bool success;
        //unordered_map<char, unordered_set<char>> adjLists = constructGraphByStrComp(words, success);
        unordered_map<char, unordered_set<char>> adjLists = constructGraphByTrie(words, success);
        if (!success) {
            return "";
        }

        unordered_map<char, int> inDegrees;
        for (const string& word : words) {
            for (char c : word) {
                inDegrees.emplace(c, 0);
            }
        }
        for (const auto& [node, nexts] : adjLists) {
            for (char next : nexts) {
                ++inDegrees[next];
            }
        }

        queue<int> q;
        for (const auto& [node, inDegree] : inDegrees) {
            if (inDegree == 0) {
                q.push(node);
            }
        }

        string ret;
        while (!q.empty()) {
            char node = q.front();
            q.pop();

            ret.push_back(node);

            for (char next : adjLists[node]) {
                if (--inDegrees[next] == 0) {
                    q.push(next);
                }
            }
        }

        return ret.size() == inDegrees.size() ? ret : "";
    }
};
