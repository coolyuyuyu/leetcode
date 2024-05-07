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
    ListNode* doubleIt(ListNode* head) {
        if (head->val >= 5) {
            head = new ListNode(0, head);
        }
        for (ListNode *cur = head, *pre = nullptr; cur; pre = cur, cur = cur->next) {
            if (cur->val >= 5) {
                pre->val += 1;
            }
            cur->val = cur->val * 2 % 10;
        }

        return head;
    }
};
