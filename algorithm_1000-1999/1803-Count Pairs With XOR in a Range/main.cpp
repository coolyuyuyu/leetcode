class Trie {
public:
    Trie()
        : m_root(new Node()){
    }

    void add(int num) {
        Node* node = m_root;
        for (int i = 15; 0 < i--;) {
            int b = (num >> i) & 1;
            if (node->nexts[b] == nullptr) {
                node->nexts[b] = new Node();
            }
            node = node->nexts[b];
            node->cnt += 1;
        }
    }

    int countPairsLT(int num, int target) {
        Node* node = m_root;

        int ret = 0;
        for (int i = 15; 0 < i--;) {
            if ((target >> i) & 1) {
                if ((num >> i) & 1) {
                    ret += (node->nexts[1] ? node->nexts[1]->cnt : 0);
                    if (node->nexts[0]) { node = node->nexts[0]; }
                    else { break; }
                }
                else {
                    ret += (node->nexts[0] ? node->nexts[0]->cnt : 0);
                    if (node->nexts[1]) { node = node->nexts[1]; }
                    else { break; }
                }
            }
            else {
                if ((num >> i) & 1) {
                    if (node->nexts[1]) { node = node->nexts[1]; }
                    else { break; }
                }
                else {
                    if (node->nexts[0]) { node = node->nexts[0]; }
                    else { break; }
                }
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
    int countPairs(vector<int>& nums, int low, int high) {
        Trie trie;

        int ret = 0;
        for (int num : nums) {
            ret += trie.countPairsLT(num, high + 1);
            ret -= trie.countPairsLT(num, low);
            trie.add(num);
        }

        return ret;
    }
};

/*
Input: nums = [1,4,2,7], low = 2, high = 6
Output: 6
Explanation: All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 5

    - (0, 2): nums[0] XOR nums[2] = 3
    - (1, 2): nums[1] XOR nums[2] = 6

    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5

Input: nums = [9,8,4,2,1], low = 5, high = 14
Output: 8
Explanation: All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 1

    - (0, 2): nums[0] XOR nums[2] = 13
    - (1, 2): nums[1] XOR nums[2] = 12
​​​​​
    - (0, 3): nums[0] XOR nums[3] = 11
    - (1, 3): nums[1] XOR nums[3] = 10
    - (2, 3): nums[2] XOR nums[3] = 6

    - (0, 4): nums[0] XOR nums[4] = 8
    - (1, 4): nums[1] XOR nums[4] = 9
    - (2, 4): nums[2] XOR nums[4] = 5
    - (3, 4): nums[3] XOR nums[4] = 3
*/
