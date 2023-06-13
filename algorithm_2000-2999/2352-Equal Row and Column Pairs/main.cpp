class Trie {
public:
    struct Node {
    public:
        Node()
            : cnt(0) {
        }

        std::unordered_map<int, Node*> childs;
        int cnt;
    };

    Trie()
        : m_root(new Node()) {
    }

    void insert(const vector<int>& nums) {
        Node* node = m_root;

        for (int num : nums) {
            if (node->childs[num] == nullptr) {
                node->childs[num] = new Node();
            }
            node = node->childs[num];
        }

        node->cnt += 1;
    }

    Node* root() {
        return m_root;
    }

private:
    Node* m_root;
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        Trie trie;
        for (int r = 0; r < n; ++r) {
            trie.insert(grid[r]);
        }

        int ret = 0;
        for (int c = 0; c < n; ++c) {
            Trie::Node* node = trie.root();
            for (int r = 0; r < n && node; ++r) {
                auto itr = node->childs.find(grid[r][c]);
                if (itr != node->childs.end()) {
                    node = itr->second;
                }
            }

            if (node) {
                ret += node->cnt;
            }
        }

        return ret;
    }
};
