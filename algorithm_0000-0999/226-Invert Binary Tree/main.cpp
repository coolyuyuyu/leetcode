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
        dfs_recv(root->left);
        dfs_recv(root->right);

        return root;
    }

    TreeNode* dfs_iter(TreeNode* root) {
        for (stack<TreeNode*> stk({root}); !stk.empty();) {
            TreeNode* root = stk.top();
            stk.pop();

            if (!root) {
                continue;
            }

            std::swap(root->left, root->right);
            stk.push(root->left);
            stk.push(root->right);
        }

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return dfs_recv(root);
        //return dfs_iter(root);
    }
};
