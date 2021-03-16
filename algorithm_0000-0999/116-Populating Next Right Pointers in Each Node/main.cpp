/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connect_Recursive(Node* root) {
        if (!root || !root->left) {
            return;
        }

        assert(root->right);

        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }

        connect_Recursive(root->left);
        connect_Recursive(root->right);
    }

    void connect_Iterative(Node* root) {
        for (Node* head = root; head && head->left; head = head->left) {
            for (Node* node = head; node; node = node->next) {
                node->left->next = node->right;
                if (node->next) {
                    node->right->next = node->next->left;
                }
            }
        }
    }

    Node* connect(Node* root) {
        //connect_Recursive(root);
        connect_Iterative(root);

        return root;
    }
};