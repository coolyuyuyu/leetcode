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
    ListNode* reverseKGroup(ListNode* pHead, int k) {
        assert(0 < k);

        ListNode** ppHead = &pHead;
        while (*ppHead) {
            ListNode* pLast = *ppHead;
            for (int i = 1; i < k && pLast; ++i) {
                pLast = pLast->next;
            }
            if (pLast == NULL) {
                break;
            }
            ListNode** ppHeadNew = &((*ppHead)->next);

            ListNode* pPre = pLast->next;
            ListNode* pCur = *ppHead;
            for (int i = 0; i < k; ++i) {
                ListNode* pNxt = pCur->next;
                pCur->next = pPre;
                pPre = pCur;
                pCur = pNxt;
            }

            *ppHead = pPre;
            ppHead = ppHeadNew;
        }

        return pHead;
    }
};