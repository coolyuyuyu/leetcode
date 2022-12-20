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
    bool hasCycle(ListNode *head) {
        for (ListNode *pFast = head, *pSlow = head; pFast && pFast->next;) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if (pFast == pSlow) {
                return true;
            }
        }

        return false;
    }
};
