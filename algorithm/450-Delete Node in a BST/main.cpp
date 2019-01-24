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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // leaf
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // one child
            if (!root->left || !root->right) {
                TreeNode* ret = root->left ? root->left : root->right;
                delete root;
                return ret;
            }

            // two childs
            TreeNode* tmp = root->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }
};