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
    TreeNode* dfs_recv(TreeNode* root) {
        if (!root) {
            return root;
        }

        std::swap(root->left, root->right);
        root->left = dfs_recv(root->left);
        root->right = dfs_recv(root->right);

        return root;
    }

    TreeNode* dfs_iter(TreeNode* root) {
        stack<TreeNode*> stk({root});
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (!node) {
                continue;
            }

            std::swap(node->left, node->right);
            stk.push(node->right);
            stk.push(node->left);
        }

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        //return dfs_recv(root);
        return dfs_iter(root);
    }
};
