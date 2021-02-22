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
    bool isSubPathHelper(ListNode* head, TreeNode* root, bool samePrefix) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }

        if (head->val == root->val && (isSubPathHelper(head->next, root->left, true) || isSubPathHelper(head->next, root->right, true))) {
            return true;
        }
        if (samePrefix){
            return false;
        }

        return isSubPathHelper(head, root->left, false) || isSubPathHelper(head, root->right, false);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPathHelper(head, root, false);
    }
};