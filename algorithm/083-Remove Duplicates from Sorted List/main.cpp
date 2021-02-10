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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** ppCur = &head;
        while (*ppCur) {
            int val = (*ppCur)->val;
            ppCur = &((*ppCur)->next);
            while (*ppCur && (*ppCur)->val == val) {
                ListNode* pDel = *ppCur;
                *ppCur = pDel->next;
                delete pDel;
            }            
        }

        return head;
    }
};