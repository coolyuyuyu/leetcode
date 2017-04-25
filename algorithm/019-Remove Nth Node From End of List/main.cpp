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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** ppFast = &head;
        while (*ppFast && n) {
            ppFast = &((*ppFast)->next);
            --n;
        }

        ListNode** ppSlow = &head;
        while (*ppFast) {
            ppFast = &((*ppFast)->next);
            ppSlow = &((*ppSlow)->next);
        }

        ListNode* pTarget = (*ppSlow);
        *ppSlow = pTarget->next;
        delete pTarget;

        return head;
    }
};