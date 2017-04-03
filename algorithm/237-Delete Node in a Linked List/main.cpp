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
    void deleteNode(ListNode* node) {
        ListNode* pNxt = node->next;
        node->val = pNxt->val;
        node->next = pNxt->next;
        delete pNxt;
    }
};