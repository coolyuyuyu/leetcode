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
    ListNode* reverse(ListNode* pHead) {
        ListNode* pCur = pHead;
        ListNode* pPre = NULL;
        while (pCur) {
            ListNode* pNxt = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNxt;
        }

        return pPre;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* pHead = NULL;
        ListNode** ppCur = &pHead;
        ListNode* pNode1 = l1;
        ListNode* pNode2 = l2;
        int carry = 0;
        while (pNode1 || pNode2 || carry) {
            int sum = carry;
            if (pNode1) {
                sum += pNode1->val;
                pNode1 = pNode1->next;
            }
            if (pNode2) {
                sum += pNode2->val;
                pNode2 = pNode2->next;
            }

            *ppCur = new ListNode(sum % 10);
            ppCur = &((*ppCur)->next);

            carry = sum / 10;
        }

        return reverse(pHead);
    }
};