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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = NULL;
        ListNode** ppCur = &pHead;

        bool carry = false;
        while (l1 || l2 || carry) {
            int num = 0;

            if (carry) {
                num += 1;
            }

            if (l1) {
                num += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                num += l2->val;
                l2 = l2->next;
            }

            if (10 <= num) {
                num %= 10;
                carry = true;
            }
            else {
                carry = false;
            }

            *ppCur = new ListNode(num);
            ppCur = &((*ppCur)->next);
        }

        return pHead;
    }
};