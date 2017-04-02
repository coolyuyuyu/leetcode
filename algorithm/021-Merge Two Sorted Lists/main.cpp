class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pHead = NULL;
        ListNode** ppCur = &pHead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                *ppCur = l1;
                l1 = l1->next;
            }
            else {
                *ppCur = l2;
                l2 = l2->next;
            }
            ppCur = &((*ppCur)->next);
        }
        if (l1) {
            *ppCur = l1;
        }
        else {
            *ppCur = l2;
        }
        return pHead;
    }
};