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
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalancedHelper(root, height);
    }

    bool isBalancedHelper(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }

        int lftHeight = 0, rhtHeight = 0;
        bool lftBalanced = isBalancedHelper(root->left, lftHeight);
        if (!lftBalanced) {
            return false;
        }
        bool rhtBalanced = isBalancedHelper(root->right, rhtHeight);
        if (!rhtBalanced) {
            return false;
        }
        
        if (1 < abs(lftHeight - rhtHeight)) {
            return false;
        }

        height = max(lftHeight, rhtHeight) + 1;
        return true;
    }
};