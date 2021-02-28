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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pNodeA = headA;
        ListNode* pNodeB = headB;
        bool restartA = false;
        bool restartB = false;
        while (pNodeA && pNodeB) {
            if (pNodeA == pNodeB) {
                return pNodeA;
            }

            pNodeA = pNodeA->next;
            if (!pNodeA && !restartA) {
                pNodeA = headB;
                restartA = true;
            }
            pNodeB = pNodeB->next;
            if (!pNodeB && !restartB) {
                pNodeB = headA;
                restartB = true;
            }
        }

        return nullptr;
    }
};