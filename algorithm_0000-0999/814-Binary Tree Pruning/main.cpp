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
    TreeNode* pruneTreeRecv(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        root->left = pruneTreeRecv(root->left);
        root->right = pruneTreeRecv(root->right);

        bool contains1 = root->val == 1 || root->left != nullptr || root->right != nullptr;
        if (!contains1) {
            root = nullptr;
        }

        return root;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return pruneTreeRecv(root);
    }
};