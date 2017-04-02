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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pHead = head;
        ListNode** ppCur = &pHead;
        while (*ppCur) {
            if ((*ppCur)->val == val) {
                ListNode* pDup = *ppCur;
                *ppCur = pDup->next;
                delete pDup;
            }
            else {
                ppCur = &((*ppCur)->next);
            }
        }
        return pHead;
    }
};