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
    ListNode *detectCycle(ListNode *head) {
        ListNode* pSlow = head;
        ListNode* pFast = head;
        while (true) {
            if (!pFast || !(pFast->next)) {
                return nullptr;
            }

            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if (pFast == pSlow) {
                break;
            }
        }

        pFast = head;
        while (pFast != pSlow) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }

        return pFast;
    }
};