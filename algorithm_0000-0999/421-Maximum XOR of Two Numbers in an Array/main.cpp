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

    int findMaximumXOR(int num) {
        Node* node = m_root;

        int ret = 0;
        for (int i = 31; 0 < i--;) {
            int b = (num >> i) & 1;
            if (node->nexts[b ^ 1]) {
                ret += (1 << i);
                node = node->nexts[b ^ 1];
            }
            else {
                node = node->nexts[b];
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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) {
            trie.add(num);
        }

        int ret = 0;
        for (int num : nums) {
            ret = std::max(ret, trie.findMaximumXOR(num));
        }

        return ret;
    }
};
