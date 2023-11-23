class Trie {
public:
    Trie()
        : m_root(new Node()) {
    }

    void add(int num) {
        Node** ppNode = &m_root;
        for (int i = 31; 0 < i--;) {
            ppNode = &((*ppNode)->nexts[(num >> i) & 1]);
            if (*ppNode == nullptr) {
                *ppNode = new Node();
            }
        }
    }

    int maximizeXor(int num) {
        Node* node = m_root;

        int ret = 0;
        for (int i = 31; 0 < i--;) {
            int b = (num >> i) & 1;
            if (node->nexts[b ^ 1]) {
                ret += (1 << i);
                node = node->nexts[b ^ 1];
            }
            else if (node->nexts[b]) {
                node = node->nexts[b];
            }
            else {
                return -1;
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

    Node* m_root;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size();

        std::sort(nums.begin(), nums.end());

        Trie trie;

        int qIndexes[n];
        std::iota(qIndexes, qIndexes + n, 0);
        std::sort(qIndexes, qIndexes + n, [&](int qIndex1, int qIndex2){ return queries[qIndex1][1] < queries[qIndex2][1]; });

        vector<int> ret(n);
        for (int i = 0, j = 0; i < n; ++i) {
            int x = queries[qIndexes[i]][0], M = queries[qIndexes[i]][1];
            for (; j < m && nums[j] <= M; ++j) {
                trie.add(nums[j]);
            }

            ret[qIndexes[i]] = trie.maximizeXor(x);
        }

        return ret;
    }
};
