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
    void flatten(TreeNode* root) {
        while (root) {
            TreeNode* lft = root->left;
            if (lft) {
                TreeNode* cur = lft;
                while (cur->right) {
                    cur = cur->right;
                }
                cur->right = root->right;
                root->left = NULL;
                root->right = lft;
            }

            root = root->right;
        }
    }
};