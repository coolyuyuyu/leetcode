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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* next = NULL;
        if (p->right) {
            next = p->right;
            while (next->left) {
                next = next->left;
            }
        }
        else {
            while (root != p) {
                if (root->val > p->val) {
                    next = root;
                    root = root->left;
                }
                else {
                    assert(root->val < p->val);
                    root = root->right;
                }
            }
        }

        return next;
    }
};