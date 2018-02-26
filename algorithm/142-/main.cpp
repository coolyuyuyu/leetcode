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
    ListNode *detectCycle(ListNode *head) {
        ListNode* pA = head;
        ListNode* pB = head;

        while (pA && pB) {
            pA = pA->next;
            if(pB->next == NULL) {
                return NULL;
            }
            pB = pB->next->next;

            if (pA == pB) {
                break;
            }
        }

        if (pB == NULL) {
            return NULL;
        }

        pA = head;
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }

        return pA;
    }
};