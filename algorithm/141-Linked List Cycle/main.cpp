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
    bool hasCycle(ListNode *head) {
        ListNode* pA = head;
        ListNode* pB = head;
        while (pA && pB) {
            pA = pA->next;
            if (pB->next == NULL) {
                return false;
            }
            pB = pB->next->next;

            if (pA == pB) {
                return true;
            }
        }

        return false;
    }
};