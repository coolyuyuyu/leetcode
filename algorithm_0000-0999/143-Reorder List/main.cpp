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
    ListNode* splitList(ListNode* head) {
        ListNode** ppSlow = &head;
        for (ListNode* pFast = head; pFast;) {
            pFast = pFast->next;
            if (pFast) {
                pFast = pFast->next;
            }
            ppSlow = &((*ppSlow)->next);
        }

        ListNode* pRet = *ppSlow;
        *ppSlow = nullptr;
        return pRet;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode** ppHead = &head;
        for (ListNode* pNode = head; pNode->next;) {
            ListNode* pTmp = pNode->next;
            pNode->next = pTmp->next;
            pTmp->next = *ppHead;
            *ppHead = pTmp;
        }

        return head;
    }

    void reorderList(ListNode* head) {
        for (ListNode *l1 = head, *l2 = reverseList(splitList(head)); l2;) {
            ListNode *tmp = l2;
            l2 = l2->next;
            tmp->next = l1->next;
            l1->next = tmp;
            l1 = tmp->next;
        }
    }
};
