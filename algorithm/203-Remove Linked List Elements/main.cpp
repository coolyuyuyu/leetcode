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