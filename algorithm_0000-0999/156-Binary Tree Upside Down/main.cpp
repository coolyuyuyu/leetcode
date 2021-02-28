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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* tmp = NULL;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        while (cur) {
            TreeNode* nxt = cur->left;
            cur->left = tmp;
            tmp = cur->right;
            cur->right = pre;

            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};