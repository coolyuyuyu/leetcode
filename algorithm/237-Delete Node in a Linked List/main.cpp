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
        assert(node && node->next);

        ListNode* pDel = node->next;
        node->val = pDel->val;
        node->next = pDel->next;
        delete pDel;
    }
};