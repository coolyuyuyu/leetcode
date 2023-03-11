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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode **ppFast = &head, **ppSlow = &head;
        while (*ppFast && (*ppFast)->next) {
            ppFast = &((*ppFast)->next->next);
            ppSlow = &((*ppSlow)->next);
        }

        ListNode *pMid = *ppSlow;
        *ppSlow = nullptr;

        return new TreeNode(pMid->val, sortedListToBST(head), sortedListToBST(pMid->next));
    }
};
