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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode** ppHead = &head;
        ListNode* pNode = *ppHead;
        while (pNode->next) {
            ListNode* pTmp = pNode->next;
            pNode->next = pTmp->next;
            pTmp->next = *ppHead;
            *ppHead = pTmp;
        }

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* pHead = nullptr;
        ListNode** ppCur = &pHead;
        for (int carry = 0; l1 || l2 || carry; ppCur = &((*ppCur)->next), carry /= 10) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }

            *ppCur = new ListNode(carry % 10);
        }

        return reverseList(pHead);
    }
};
