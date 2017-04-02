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
    ListNode* reverseList(ListNode* head) {
        ListNode** ppCur = &head;
        ListNode* pPre = NULL;
        while (*ppCur) {
            ListNode* pNxt = (*ppCur)->next;
            (*ppCur)->next = pPre;
            pPre = *ppCur;
            *ppCur = pNxt;
        }
        return pPre;
    }
};