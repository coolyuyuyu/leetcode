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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pNodeA = headA;
        ListNode* pNodeB = headB;
        bool restartA = false;
        bool restartB = false;
        while (pNodeA && pNodeB) {
            if (pNodeA == pNodeB) {
                return pNodeA;
            }

            pNodeA = pNodeA->next;
            if (pNodeA == NULL) {
                if (restartA) {
                    return NULL;
                }
                pNodeA = headB;
                restartA = true;
            }
            

            pNodeB = pNodeB->next;
            if (pNodeB == NULL) {
                if (restartB) {
                    return NULL;
                }
                pNodeB = headA;
                restartB = true;
            }
        }

        return NULL;
    }
};