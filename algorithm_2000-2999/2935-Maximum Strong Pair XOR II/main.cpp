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
        Node* node = m_root;

        int ret = 0;
        for (int i = 20; 0 < i--;) {
            int b = (num >> i) & 1;
            if (node->next[b ^ 1] && node->next[b ^ 1]->cnt > 0) {
                ret += (1 << i);
                node = node->next[b ^ 1];
            }
            else if (node->next[b] && node->next[b]->cnt > 0) {
                node = node->next[b];
            }
            else {
                return 0;
            }
        }

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
