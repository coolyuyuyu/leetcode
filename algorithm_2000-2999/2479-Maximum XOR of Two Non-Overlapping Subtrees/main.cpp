class Trie {
public:
    Trie(int bitCnt)
        : m_bitCnt(bitCnt)
        , m_root(new Node()) {
    }

    void add(long long num) {
        Node** ppNode = &m_root;
        for (int i = m_bitCnt; 0 < i--;) {
            ppNode = &((*ppNode)->nexts[(num >> i) & 1]);
            if (*ppNode == nullptr) {
                *ppNode = new Node();
            }
        }
    }

    long long maxXor(long long num) {
        Node* node = m_root;

        long long ret = 0;
        for (int i = m_bitCnt; 0 < i--;) {
            long long b = (num >> i) & 1;
            if (node->nexts[b ^ 1]) {
                ret += (1LL << i);
                node = node->nexts[b ^ 1];
            }
            else if (node->nexts[b]) {
                node = node->nexts[b];
            }
            else {
                return 0;
            }
        }

        return ret;
    }

private:
    struct Node {
        Node* nexts[2];

        Node() {
            nexts[0] = nexts[1] = nullptr;
        }
    };

    int m_bitCnt;
    Node* m_root;
};

class Solution {
public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        int root = 0;
        vector<int> nexts[n];
        for (const auto& edge : edges) {
            nexts[edge[0]].push_back(edge[1]);
            nexts[edge[1]].push_back(edge[0]);
        }

        long long sums[n];
        std::function<long long(int, int)> dfs1 = [&](int cur, int pre) {
            sums[cur] = values[cur];
            for (int nxt : nexts[cur]) {
                if (nxt == pre) { continue; }
                sums[cur] += dfs1(nxt, cur);
            }
            return sums[cur];
        };
        dfs1(root, -1);

        Trie trie(std::floor(std::log2(sums[root])) + 1);

        long long ret = 0;
        std::function<void(int, int)> dfs2 = [&](int cur, int pre) {
            long long x = trie.maxXor(sums[cur]);
            ret = std::max(ret, x);

            for (int nxt : nexts[cur]) {
                if (nxt == pre) { continue; }
                dfs2(nxt, cur);
            }

            trie.add(sums[cur]);
        };
        dfs2(root, -1);

        return ret;
    }
};
