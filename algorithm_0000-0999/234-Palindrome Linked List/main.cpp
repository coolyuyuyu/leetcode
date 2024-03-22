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
        assert(head);

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
        ListNode* node1 = head;
        ListNode* node2 = reverseList(middleNode(head));
        for (; node2; node1 = node1->next, node2 = node2->next) {
            if (node1->val != node2->val) {
                return false;
            }
        }

        return true;
    }
};
