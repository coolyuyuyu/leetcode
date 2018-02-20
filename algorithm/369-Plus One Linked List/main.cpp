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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* pCur = head;
        while (pCur) {
            stk.push(pCur);
            pCur = pCur->next;
        }

        bool carry = true;
        while (!stk.empty()) {
            pCur = stk.top();
            stk.pop();
            if (carry) {
                if (pCur->val == 9) {
                    pCur->val = 0;
                }
                else {
                    carry = false;
                    ++pCur->val;
                }
            }

            if (!carry) {
                return head;
            }
        }

        if (carry) {
            pCur = new ListNode(1);
            pCur->next = head;
            head = pCur;
        }

        return head;
    }
};