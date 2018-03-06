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
    bool isIdentical(TreeNode* s, TreeNode* t) {
        if (s) {
            if (t) {
                return s->val == t->val && isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
            }
            else {
                return false;
            }
        }
        else {
            if (t) {
                return false;
            }
            else {
                return true;
            }
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isIdentical(s, t)) {
            return true;
        }
        else {
            if (s) {
                return isSubtree(s->left, t) || isSubtree(s->right, t);
            }
            else {
                return false;
            }
        }
    }
};