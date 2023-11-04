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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode** ppCur = &head;
        bool carry = false;
        while (l1 || l2 || carry) {
            int d = 0;
            if (l1) {
                d += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                d += l2->val;
                l2 = l2->next;
            }
            if (carry) {
                d += 1;
            }
            carry = (d >= 10);

            *ppCur = new ListNode(d % 10);
            ppCur = &((*ppCur)->next);
        }

        return head;
    }
};
