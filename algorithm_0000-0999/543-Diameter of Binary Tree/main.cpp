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
    int diameterOfBinaryTreeHelper(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return 0;
        }
        
        int lftDepth, rhtDepth;
        int lftMaxDiameter = diameterOfBinaryTreeHelper(root->left, lftDepth);
        int rhtMaxDiameter = diameterOfBinaryTreeHelper(root->right, rhtDepth);
        int diameter = lftDepth + rhtDepth;

        depth = max(lftDepth, rhtDepth) + 1;
        return max(diameter, max(lftMaxDiameter, rhtMaxDiameter));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dummy;
        return diameterOfBinaryTreeHelper(root, dummy);
    }
};