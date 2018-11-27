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
    void postorderTraversalIter(TreeNode* root, vector<int>& vals) {
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            vals.push_back(node->val);

            if (node->left) {
                stk.push(node->left);
            }
            if (node->right) {
                stk.push(node->right);
            }
        }

        reverse(vals.begin(), vals.end());
    }

    void postorderTraversalRecv(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        postorderTraversalRecv(root->left, vals);
        postorderTraversalRecv(root->right, vals);
        vals.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;

        postorderTraversalIter(root, vals);
        //postorderTraversalRecv(root, vals);

        return vals;
    }
};