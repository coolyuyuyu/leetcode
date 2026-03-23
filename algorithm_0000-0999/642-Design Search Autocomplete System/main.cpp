class AutocompleteSystem {
    struct Node {
        array<Node*, 27> nexts;
        int times;

        Node() {
            nexts.fill(nullptr);
            times = 0;
        }

        static int toIndex(char c) {
            return (c == ' ' ? 26 : (c - 'a'));
        }

        static char toChar(int idx) {
            return (idx == 26 ? ' ' : ('a' + idx));
        }
    };

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
        if (m_cur->nexts[idx] == nullptr) {
            m_cur->nexts[idx] = new Node();
        }
        m_cur = m_cur->nexts[idx];
        m_inputs += c;

        priority_queue<pair<int, string>> maxPQ;
        traverse(m_cur, m_inputs, 3, maxPQ);

        vector<string> ret(maxPQ.size());
        for (int i = ret.size() - 1; !maxPQ.empty(); --i, maxPQ.pop()) {
            ret[i] = maxPQ.top().second;
        }

        return ret;
    }

private:
    void add(const string& sentence, int time) {
        Node* node = m_root;
        for (char c : sentence) {
            int idx = Node::toIndex(c);
            if (node->nexts[idx] == nullptr) {
                node->nexts[idx] = new Node();
            }
            node = node->nexts[idx];
        }

        node->times = time;
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
        for (int idx = 0; idx < node->nexts.size(); ++idx) {
            if (node->nexts[idx] == nullptr) { continue; }
            prefix.push_back(Node::toChar(idx));
            traverse(node->nexts[idx], prefix, k, pq);
            prefix.pop_back();
        }
    }

    Node* m_root;

    Node* m_cur;
    string m_inputs;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
