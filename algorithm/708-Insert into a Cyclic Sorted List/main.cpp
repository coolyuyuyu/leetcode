\/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* pHead, int val) {
        if (!pHead) {
            Node* pNodeInsert = new Node(val, nullptr);
            pNodeInsert->next = pNodeInsert;
            return pNodeInsert;
        }

        Node* pPre = pHead;
        Node* pCur = pHead->next;
        bool inserted = false;
        do {
            if ((pPre->val <= val && val <= pCur->val) ||
                (pCur->val < pPre->val && pPre->val < val) ||
                (pCur->val < pPre->val && val < pCur->val)) {
                pPre->next = new Node(val, pCur);
                inserted = true;
            }
            pPre = pCur;
            pCur = pCur->next;
        } while (pPre != pHead && !inserted);

        if (!inserted) {
            pPre->next = new Node(val, pCur);
        }

        return pHead;
    }
};