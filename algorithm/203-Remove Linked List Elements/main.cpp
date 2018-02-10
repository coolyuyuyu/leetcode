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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** ppCur = &head;
        while (*ppCur) {
            if ((*ppCur)->val == val) {
                ListNode* pDel = *ppCur;
                *ppCur = pDel->next;
                delete pDel;
            }
            else {
                ppCur = &((*ppCur)->next);
            }
        }
        return head;
    }
};