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
    int pairSum(ListNode* head) {
        ListNode **ppFast = &head, **ppSlow = &head;
        while (*ppFast) {
            ppFast = &((*ppFast)->next->next);
            ppSlow = &((*ppSlow)->next);
        }

        for (ListNode* pCur = *ppSlow; pCur->next;) {
            ListNode* pNxt = pCur->next;
            pCur->next = pNxt->next;
            pNxt->next = *ppSlow;
            *ppSlow = pNxt;
        }

        int ret = 0;
        for (ListNode *pCur1 = head, *pCur2 = *ppSlow;  pCur2; pCur1 = pCur1->next, pCur2 = pCur2->next) {
            ret = std::max(ret, pCur1->val + pCur2->val);
        }

        return ret;
    }
};
