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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode **ppFast = &head, **ppSlow = &head;
        while (*ppFast && (*ppFast)->next) {
            ppFast = &((*ppFast)->next->next);
            ppSlow = &((*ppSlow)->next);
        }
        *ppSlow = (*ppSlow)->next;

        return head;
    }
};
