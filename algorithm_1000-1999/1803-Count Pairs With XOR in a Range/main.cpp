class Trie {
public:
    Trie()
        : m_root(new Node()){
    }

    void add(int num) {
        Node* node = m_root;
        for (int i = 15; 0 < i--;) {
            int b = (num >> i) & 1;
            if (node->next[b] == nullptr) {
                node->next[b] = new Node();
            }
            node = node->next[b];
            node->cnt += 1;
        }
    }

    int countPairsGE(int num, int target) {
        int ret = 0;
        std::function<void(Node*, int, int)> dfs = [&](Node* node, int i, int xxor) {
            if (i < 0 || xxor + (1 << i) + (1 << i) - 1 < target) {
                return;
            }

            int b = (num >> i) & 1;
            if (node->next[b ^ 1]) {
                if (xxor + (1 << i) >= target) {
                    ret += node->next[b ^ 1]->cnt;
                }
                else if (node->next[b ^ 1]->cnt){
                    dfs(node->next[b ^ 1], i - 1, xxor +(1 << i));
                }
            }

            if (node->next[b] && node->next[b]->cnt) {
                dfs(node->next[b], i - 1, xxor);
            }
        };
        dfs(m_root, 14, 0);

        return ret;
    }

private:
    struct Node {
        Node* next[2];
        int cnt;

        Node() {
            next[0] = next[1] = nullptr;
            cnt = 0;
        }
    };

    Node* m_root;
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie trie;

        int ret = 0;
        for (int num : nums) {
            ret += trie.countPairsGE(num, low);
            ret -= trie.countPairsGE(num, high + 1);
            trie.add(num);
        }

        return ret;
    }
};
