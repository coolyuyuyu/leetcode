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
    ListNode* reverseList(ListNode* head) {
        ListNode* pCur = head;
        ListNode* pPre = NULL;
        while (pCur) {
            ListNode* pNxt = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNxt;
        }

        return pPre;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        
        ListNode* pA = head;
        ListNode* pB = head;
        while (pA && pA->next && pA->next->next) {
            pA = pA->next->next;
            pB = pB->next;
        }
        
        pB->next = reverseList(pB->next);
        
        pA = head;
        pB = pB->next;
        while (pB) {
            if (pA->val != pB->val) {
                return false;
            }
            pA = pA->next;
            pB = pB->next;
        }
        
        return true;
    }
};