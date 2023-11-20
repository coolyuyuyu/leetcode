class Trie {
public:
    Trie()
        : m_root(new Node()){
    }

    void add(int num) {
        Node* node = m_root;
        for (int i = 20; 0 < i--;) {
            int b = (num >> i) & 1;
            if (node->next[b] == nullptr) {
                node->next[b] = new Node();
            }
            node = node->next[b];
            node->cnt += 1;
        }
    }

    void remove(int num) {
        Node* node = m_root;
        for (int i = 20; 0 < i--;) {
            int b = (num >> i) & 1;
            node = node->next[b];
            node->cnt -= 1;
        }
    }

    int maximumXor(int num) {
        std::function<int(Node*, int)> dfs = [&](Node* node, int i) {
            if (i < 0) { return 0; }
            int b = (num >> i) & 1;
            if (b == 0) {
                if (node->next[1] && node->next[1]->cnt > 0) {
                    return dfs(node->next[1], i - 1) + (1 << i);
                }
                else if (node->next[0] && node->next[0]->cnt > 0) {
                    return dfs(node->next[0], i - 1);
                }
            }
            else {
                if (node->next[0] && node->next[0]->cnt > 0) {
                    return dfs(node->next[0], i - 1) + (1 << i);
                }
                else if (node->next[1] && node->next[1]->cnt > 0) {
                    return dfs(node->next[1], i - 1);
                }
            }

            return INT_MIN;
        };

        return dfs(m_root, 20 - 1);

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
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        Trie trie;

        int ret = INT_MIN;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            for (; rht < n && nums[lft] * 2 >= nums[rht]; ++rht) {
                trie.add(nums[rht]);
            }

            ret = std::max(ret, trie.maximumXor(nums[lft]));

            trie.remove(nums[lft]);
        }

        return ret;
    }
};

// |x - y| <= min(x, y)
// => assume x >= y
// => x - y <= y
// => x <= 2y
// => y <= x <= 2y
