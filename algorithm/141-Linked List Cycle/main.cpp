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
        ListNode *pNodeA = head;
        ListNode *pNodeB = head;
        while (pNodeA && pNodeB) {
            pNodeA = pNodeA->next;
            if (pNodeB->next == NULL) {
                return false;
            }
            pNodeB = pNodeB->next->next;
            
            if (pNodeA == pNodeB) {
                return true;
            }
        }
        
        return false;
    }
};