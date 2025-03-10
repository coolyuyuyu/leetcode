class AutocompleteSystem {
private:
    struct Node {
        std::array<Node*, 27> childs;
        int times;

        static int toIndex(char c) {
            return c == ' ' ? 0 : (1 + c - 'a');
        }

        static char toChar(int idx) {
            return idx == 0 ? ' ' : ('a' + idx - 1);
        }

        Node() {
            childs.fill(nullptr);
            times = 0;
        }
    };

    void add(const string& sentence, int times) {
        Node* node = m_root;
        for (char c : sentence) {
            int idx = Node::toIndex(c);
            if (node->childs[idx] == nullptr) {
                node->childs[idx] = new Node();
            }
            node = node->childs[idx];
        }
        node->times = times;
    }

    template<class T>
    void traverse(Node* node, string& prefix, int k, T& pq) {
        assert(node);

        if (node->times) {
            pq.emplace(0 - node->times, prefix);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        for (int idx = 0; idx < node->childs.size(); ++idx) {
            if (node->childs[idx] == nullptr) { continue; }
            prefix.push_back(Node::toChar(idx));
            traverse(node->childs[idx], prefix, k, pq);
            prefix.pop_back();
        }
    }

    Node* m_root;

    Node* m_cur;
    string m_inputs;

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times)
        : m_root(new Node())
        , m_cur(m_root) {
        for (int i = 0, n = sentences.size(); i < n; ++i) {
            add(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            m_cur->times += 1;

            m_cur = m_root;
            m_inputs.clear();
            return {};
        }

        int idx = Node::toIndex(c);
        if (m_cur->childs[idx] == nullptr) {
            m_cur->childs[idx] = new Node();
        }
        m_cur = m_cur->childs[idx];
        m_inputs += c;

        priority_queue<pair<int, string>> pq;
        traverse(m_cur, m_inputs, 3, pq);

        vector<string> ret(pq.size());
        for (int i = ret.size() - 1; !pq.empty(); --i, pq.pop()) {
            ret[i] = pq.top().second;
        }
        return ret;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
