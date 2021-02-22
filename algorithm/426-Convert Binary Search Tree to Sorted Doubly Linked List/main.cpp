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

    Node* treeToDoublyList_Iterative(Node* root) {
        Node* pHead = nullptr;

        stack<Node*> stk;
        Node* pCur = root;
        while (pCur || !stk.empty()) {
            if (pCur) {
                stk.emplace(pCur);
                pCur = pCur->left;
            }
            else {
                pCur = stk.top();
                stk.pop();
                Node* pRht = pCur->right;

                if (!pHead) {
                    pHead = pCur;
                    pHead->left = pHead->right = pHead;
                }
                else {
                    pCur->left = pHead->left;
                    pCur->right = pHead;
                    pHead->left->right = pCur;
                    pHead->left = pCur;
                }

                pCur = pRht;
            }
        }

        return pHead;
    }

    Node* treeToDoublyList(Node* root) {
        //return treeToDoublyList_Recursive(root);
        return treeToDoublyList_Iterative(root);
    }
};