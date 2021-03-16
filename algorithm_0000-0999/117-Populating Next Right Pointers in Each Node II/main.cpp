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
    // Space: O(max level)
    void connect_Iterative1(Node* root) {
        // top-down level order traversal
        queue<Node*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            Node* pHead = nullptr;
            Node** ppNode = &pHead;
            for (size_t i = q.size(); 0 < i; --i) {
                Node* pCur = q.front();
                q.pop();

                *ppNode = pCur;
                ppNode = &(pCur->next);

                if (pCur->left) {
                    q.push(pCur->left);
                }
                if (pCur->right) {
                    q.push(pCur->right);
                }
            }
        }
    }

    // Space: O(1)
    void connect_Iterative2(Node* root) {
        for (Node *pHead = root, *pChildHead = nullptr; pHead; pHead = pChildHead, pChildHead = nullptr) {
            Node** ppChildNode = &pChildHead;
            for (Node* pNode = pHead; pNode; pNode = pNode->next) {
                if (pNode->left) {
                    *ppChildNode = pNode->left;
                    ppChildNode = &((*ppChildNode)->next);
                }
                if (pNode->right) {
                    *ppChildNode = pNode->right;
                    ppChildNode = &((*ppChildNode)->next);
                }
            }
        }
    }

    Node* connect(Node* root) {
        //connect_Iterative1(root);
        connect_Iterative2(root);

        return root;
    }
};