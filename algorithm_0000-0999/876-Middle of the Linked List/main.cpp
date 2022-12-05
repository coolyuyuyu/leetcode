/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* pFast = head;
        ListNode* pSlow = head;
        while (pFast && pFast->next) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }

        return pSlow;
    }
};
