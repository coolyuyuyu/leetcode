class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pHead = head;
        ListNode** ppCur = &pHead;

        while (*ppCur) {
            ListNode **ppPre = ppCur;
            int val = (*ppPre)->val;
            ppCur = &((*ppCur)->next);
            while (*ppCur && (*ppCur)->val == val) {
                ListNode *pDup = *ppCur;
                ppCur = &(pDup->next);
                delete pDup;
            }
            (*ppPre)->next = *ppCur;
        }

        return pHead;
    }
};