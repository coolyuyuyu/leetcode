/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* append(Node* l1, Node* l2) {
        if (!l1 || !l2) {
            return (l1 ? l1 : l2);
        }
        else {
            swap(l1->left->right, l2->left->right);
            swap(l1->left, l2->left);
            return l1;
        }
    }

    Node* treeToDoublyList_Recursive(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node* lftChild = treeToDoublyList_Recursive(root->left);
        Node* rhtChild = treeToDoublyList_Recursive(root->right);
        root->left = root->right = root;

        return append(append(lftChild, root), rhtChild);
    }

    Node* treeToDoublyList(Node* root) {
        return treeToDoublyList_Recursive(root);
    }
};