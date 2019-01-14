/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    void flatten(Node* pHead, Node** ppTail) {
        if (!pHead) {
            return;
        }

        for (Node* pCur = pHead; pCur; pCur = pCur->next) {
            if (pCur->child) {
                Node* pChildHead = pCur->child;
                Node* pChildTail = nullptr;
                flatten(pChildHead, &pChildTail);

                pChildHead->prev = pCur;
                pChildTail->next = pCur->next;
                if (pChildTail->next) {
                    pChildTail->next->prev = pChildTail;
                }
                pCur->next = pCur->child;
                pCur->child = nullptr;

                pCur = pChildTail;
            }
            *ppTail = pCur;
        }


    }
    Node* flatten(Node* pHead) {
        Node* pTail = nullptr;
        flatten(pHead, &pTail);
        return pHead;
    }
};