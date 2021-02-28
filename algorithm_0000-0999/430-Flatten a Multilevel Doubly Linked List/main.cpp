/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void flattenHelper(Node* pHead, Node*& pTail) {
        assert(pHead);

        for (Node* pCur = pHead; pCur; pCur = pCur->next) {
            if (pCur->child) {
                Node* pChildHead = pCur->child;
                Node* pChildTail;
                flattenHelper(pChildHead, pChildTail);

                pChildHead->prev = pCur;
                pChildTail->next = pCur->next;
                if (pCur->next) {
                    pCur->next->prev = pChildTail;
                }
                pCur->next = pChildHead;

                pCur->child = nullptr;
                pCur = pChildTail;
            }

            pTail = pCur;
        }
    }

    Node* flatten(Node* pHead) {
        if (pHead) {
            Node* pTail;
            flattenHelper(pHead, pTail);
        }
        return pHead;
    }
};