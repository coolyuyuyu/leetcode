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
    ListNode* quicksortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }

        ListNode* pHead1 = NULL;
        ListNode** ppCur1 = &pHead1;
        ListNode* pHead2 = NULL;
        ListNode** ppCur2 = &pHead2;

        ListNode* pPivot = head;
        ListNode* pCur = pPivot->next;
        while (pCur) {
            if (pCur->val < pPivot->val) {
                *ppCur1 = pCur;
                ppCur1 = &((*ppCur1)->next);
            }
            else {
                *ppCur2 = pCur;
                ppCur2 = &((*ppCur2)->next);
            }
            pCur = pCur->next;
        }
        *ppCur1 = NULL;
        *ppCur2 = NULL;

        pHead1 = quicksortList(pHead1);
        ListNode** ppCur = &pHead1;
        while (*ppCur) {
            ppCur = &((*ppCur)->next);
        }

        *ppCur = pPivot;

        pHead2 = quicksortList(pHead2);
        pPivot->next = pHead2;

        return pHead1;
    }

    ListNode* sortList(ListNode* head) {
        return quicksortList(head);
    }
};