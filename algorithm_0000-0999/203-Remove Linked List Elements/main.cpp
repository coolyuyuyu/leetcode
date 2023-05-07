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
        for (ListNode** ppCur = &head; *ppCur;) {
            if ((*ppCur)->val == val) {
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

