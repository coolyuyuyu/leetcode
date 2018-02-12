/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBSTHelper(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next != tail && fast->next->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* pRoot = new TreeNode(slow->val);
        pRoot->left = sortedListToBSTHelper(head, slow);
        pRoot->right = sortedListToBSTHelper(slow->next, tail);
        return pRoot;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBSTHelper(head, NULL);
    }
};