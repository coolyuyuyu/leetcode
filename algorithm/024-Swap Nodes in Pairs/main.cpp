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
    ListNode* swapPairs(ListNode* head) {
        ListNode** ppCur = &head;
        while (*ppCur) {
            if ((*ppCur)->next) {
                ListNode *pNxt = (*ppCur)->next;
                (*ppCur)->next = pNxt->next;
                pNxt->next = *ppCur;
                (*ppCur) = pNxt;
                
                ppCur = &((*ppCur)->next->next);
            }
            else {
                ppCur = &((*ppCur)->next);
            }
        }

        return head;
    }
};