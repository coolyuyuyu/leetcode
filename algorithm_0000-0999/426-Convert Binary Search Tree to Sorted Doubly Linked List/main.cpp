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
        if (l1 && l2) {
            swap(l1->left->right, l2->left->right);
            swap(l1->left, l2->left);
            return l1;
        }
        else {
            return (l1 ? l1 : l2);
        }
    }

    Node* treeToDoublyList_Recursive(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node* lft = treeToDoublyList_Recursive(root->left);
        Node* rht = treeToDoublyList_Recursive(root->right);
        root->left = root->right = root;
        return append(append(lft, root), rht);
    }

    Node* treeToDoublyList_Iterative(Node* root) {
        Node* head = nullptr;

        // inorder traversal
        stack<pair<Node*, bool>> stk;
        if (root) {
            stk.emplace(root, nullptr);
        }
        while (!stk.empty()) {
            Node* node = stk.top().first;
            bool visited = stk.top().second;
            stk.pop();

            if (visited) {
                node->left = node->right = node;
                head = append(head, node);
            }
            else {
                if (node->right) {
                    stk.emplace(node->right, false);
                }
                stk.emplace(node, true);
                if (node->left) {
                    stk.emplace(node->left, false);
                }
            }
        }

        return head;
    }

    Node* treeToDoublyList(Node* root) {
        //return treeToDoublyList_Recursive(root);
        return treeToDoublyList_Iterative(root);
    }
};