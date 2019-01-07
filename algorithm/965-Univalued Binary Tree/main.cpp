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
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (root->left && (root->val != root->left->val || !isUnivalTree(root->left))) {
            return false;
        }
        if (root->right && (root->val != root->right->val || !isUnivalTree(root->right))) {
            return false;
        }

        return true;
    }
};