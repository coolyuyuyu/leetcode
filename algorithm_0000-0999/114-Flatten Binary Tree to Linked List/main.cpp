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
    void flatten_Recursive(TreeNode* root) {
        if (!root) {
            return;
        }

        flatten_Recursive(root->left);
        if (root->left) {
            TreeNode* node = root->left;
            while (node->right) {
                node = node->right;
            }
            node->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        flatten_Recursive(root->right);
    }

    void flatten_Iterative(TreeNode* root) {
        for (; root; root = root->right) {
            if (root->left) {
                TreeNode* node = root->left;
                while (node->right) {
                    node = node->right;
                }
                node->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
        }
    }

    void flatten(TreeNode* root) {
        //flatten_Recursive(root);
        flatten_Iterative(root);
    }
};