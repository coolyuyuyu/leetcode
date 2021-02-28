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
    void preorderTraversalIter(TreeNode* root, vector<int>& vals) {
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            vals.push_back(node->val);

            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
    }

    void preorderTraversalRecv(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        vals.push_back(root->val);
        preorderTraversalRecv(root->left, vals);
        preorderTraversalRecv(root->right, vals);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals;

        preorderTraversalIter(root, vals);
        //preorderTraversalRecv(root, vals);

        return vals;
    }
};