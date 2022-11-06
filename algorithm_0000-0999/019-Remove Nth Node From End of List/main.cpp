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
    ListNode* removeNthFromEnd(ListNode* pHead, int n) {
        ListNode** ppFast = &pHead;
        while (0 < n--) {
            ppFast = &((*ppFast)->next);
        }

        ListNode** ppSlow = &pHead;
        while (*ppFast) {
            ppFast = &((*ppFast)->next);
            ppSlow = &((*ppSlow)->next);
        }

        ListNode* pDel = *ppSlow;
        *ppSlow = pDel->next;
        delete pDel;

        return pHead;
    }
};
