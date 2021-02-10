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
    ListNode* middleNode(ListNode* head) {
        ListNode* pSlow = head;
        ListNode* pFast = head;
        while (pFast && pFast->next) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }

        return pSlow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pPre = nullptr;
        ListNode* pCur = head;
        while (pCur) {
            ListNode* pNxt = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNxt;
        }

        return pPre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* pNode1 = head;
        ListNode* pNode2 = reverseList(middleNode(head));
        while (pNode2) {
            if (pNode1->val != pNode2->val) {
                return false;
            }
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }

        return true;
    }
};