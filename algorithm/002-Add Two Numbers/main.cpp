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
        ListNode* pHead = nullptr;
        ListNode** ppNode = &pHead;
        bool carry = false;
        while (l1 || l2 || carry) {
            int digit = 0;
            if (carry) {
                digit += 1;
            }
            if(l1) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                digit += l2->val;
                l2 = l2->next;
            }

            *ppNode = new ListNode(digit % 10);
            ppNode = &((*ppNode)->next);

            carry = (10 <= digit);
        }

        return pHead;
    }
};