/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* head = nullptr;

        stack<Node*> stk;
        Node* cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                cur = stk.top();
                stk.pop();

                Node* rhtChild = cur->right;

                if (!head) {
                    head = cur;
                    cur->left = cur;
                    cur->right = cur;
                }
                else {
                    cur->left = head->left;
                    cur->right = head;
                    head->left->right = cur;
                    head->left = cur;
                }

                cur = rhtChild;
            }
        }

        return head;
    }
};