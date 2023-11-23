class Trie {
public:
    Trie()
        : m_root(new Node) {
    }

    void add(int num) {
        Node** ppNode = &m_root;
        for (int i = 18; 0 < i--;) {
            ppNode = &((*ppNode)->nexts[(num >> i) & 1]);
            if (*ppNode == nullptr) {
                *ppNode = new Node();
            }
            (*ppNode)->cnt += 1;
        }
    }

    void remove(int num) {
        Node** ppNode = &m_root;
        for (int i = 18; 0 < i--;) {
            ppNode = &((*ppNode)->nexts[(num >> i) & 1]);
            (*ppNode)->cnt -= 1;
        }
    }

    int maxGeneticDifference(int num) {
        Node* node = m_root;
        int ret = 0;
        for (int i = 18; 0 < i--;) {
            int b = (num >> i) & 1;
            if (node->nexts[b ^ 1] && node->nexts[b ^ 1]->cnt) {
                ret += (1 << i);
                node = node->nexts[b ^ 1];
            }
            else {
                assert(node->nexts[b]->cnt);
                node = node->nexts[b];
            }
        }

        return ret;
    }

private:
    struct Node {
        Node* nexts[2];
        int cnt;

        Node() {
            nexts[0] = nexts[1] = nullptr;
            cnt = 0;
        }
    };

    Node* m_root;
};

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size(), m = queries.size();

        int root;
        vector<int> nexts[n];
        for (int i = 0; i < n; ++i) {
            if (parents[i] == -1) {
                root = i;
                continue;
            }
            nexts[parents[i]].push_back(i);
        }

        unordered_map<int, vector<pair<int, int>>> queryMap;
        for (int j = 0; j < m; ++j) {
            int node = queries[j][0], val = queries[j][1];
            queryMap[node].emplace_back(val, j);
        }

        Trie trie;

        vector<int> ret(m);
        std::function<void(int)> dfs = [&](int cur) {
            trie.add(cur);
            for (const auto& [val, qIdx] : queryMap[cur]) {
                ret[qIdx] = trie.maxGeneticDifference(val);
            }

            for (int nxt : nexts[cur]) {
                dfs(nxt);
            }

            trie.remove(cur);
        };
        dfs(root);

        return ret;
    }
};
