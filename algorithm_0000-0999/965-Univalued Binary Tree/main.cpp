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
    bool isUnivalTree_Recursive(TreeNode* root, int val) {
        if (!root) {
            return true;
        }

        return (root->val == val) && isUnivalTree_Recursive(root->left, val) && isUnivalTree_Recursive(root->right, val);
    }

    bool isUnivalTree_Iterative(TreeNode* root, int val) {
        stack<TreeNode*> stk({root});
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (node->val != val) {
                return false;
            }

            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }

        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        assert(root);

        //return isUnivalTree_Recursive(root, root->val);
        return isUnivalTree_Iterative(root, root->val);
    }
};