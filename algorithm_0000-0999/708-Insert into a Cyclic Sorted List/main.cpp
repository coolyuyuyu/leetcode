/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        Node* pPre = head;
        Node* pCur = pPre->next;
        do {
            if ((pPre->val <= insertVal && insertVal <= pCur->val) ||
                (pCur->val < pPre->val && pPre->val <= insertVal) ||
                (pCur->val < pPre->val && insertVal <= pCur->val)) {
                pPre->next = new Node(insertVal, pCur);
                return head;
            }
            pPre = pCur;
            pCur = pCur->next;
        } while (pPre != head);

        pPre->next = new Node(insertVal, pCur);
        return head;
    }
};
