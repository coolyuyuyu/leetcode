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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** ppCur = &head;
        while (*ppCur) {
            while ((*ppCur)->next && (*ppCur)->val == (*ppCur)->next->val) {
                ListNode* pDel = *ppCur;
                *ppCur = (*ppCur)->next;
                delete pDel;
            }
            ppCur = &((*ppCur)->next);
        }
        
        return head;
    }
};