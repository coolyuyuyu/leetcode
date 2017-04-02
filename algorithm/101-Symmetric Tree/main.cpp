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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode* lft, TreeNode* rht) {
        if (lft) {
            if (rht) {
                if (lft->val == rht->val) {
                    return isSymmetricHelper(lft->left, rht->right) && isSymmetricHelper(lft->right, rht->left);
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            if (rht) {
                return false;
            }
            else {
                return true;
            }
        }
    }
};