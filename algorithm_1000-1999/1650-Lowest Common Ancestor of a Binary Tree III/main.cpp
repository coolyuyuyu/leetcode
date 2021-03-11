/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        size_t depth1 = 0;
        for (Node* node = p; node->parent; node = node->parent) {
            ++depth1;
        }
        size_t depth2 = 0;
        for (Node* node = q; node->parent; node = node->parent) {
            ++depth2;
        }

        if (depth1 < depth2) {
            swap(depth1, depth2);
            swap(p, q);
        }
        for (size_t i = depth1 - depth2; 0 < i; --i) {
            p = p->parent;
        }

        while (p != q) {
            p = p->parent;
            q = q->parent;
        }

        return p;
    }
};