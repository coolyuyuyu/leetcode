/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* pLftHead = NULL;
        ListNode** ppLftCur = &pLftHead;
        ListNode* pRhtHead = NULL;
        ListNode** ppRhtCur = &pRhtHead;

        ListNode* pCur = head;
        while (pCur) {
            if (pCur->val < x) {
                *ppLftCur = pCur;
                ppLftCur = &((*ppLftCur)->next);
            }
            else {
                *ppRhtCur = pCur;
                ppRhtCur = &((*ppRhtCur)->next);
            }
            pCur = pCur->next;
        }

        *ppLftCur = pRhtHead;
        *ppRhtCur = NULL;

        return pLftHead;
    }
};