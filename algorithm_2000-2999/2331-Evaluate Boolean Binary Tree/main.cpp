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
    bool evaluateTree(TreeNode* root) {
        switch (root->val) {
        case 0: return false;
        case 1: return true;
        case 2: return evaluateTree(root->left) | evaluateTree(root->right);
        case 3: return evaluateTree(root->left) & evaluateTree(root->right);
        default:
            return false;
        }
    }
};
