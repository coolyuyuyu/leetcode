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
        for (ListNode** ppCur = &head; *ppCur;) {
            if ((*ppCur)->next && (*ppCur)->val == (*ppCur)->next->val) {
                ListNode* tmp = *ppCur;
                *ppCur = tmp->next;

                delete tmp;
            }
            else {
                ppCur = &((*ppCur)->next);
            }
        }

        return head;
    }
};
