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
    void postorderTraversal_Recursive(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }
        
        postorderTraversal_Recursive(root->left, vals);
        postorderTraversal_Recursive(root->right, vals);
        vals.push_back(root->val);
    }
    
    void postorderTraversal_Iterative(TreeNode* root, vector<int>& vals) {
        stack<TreeNode*> stk;
        if (root) {
            stk.push(root);
        }
        
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            
            vals.push_back(root->val);
            
            if (root->left) {
                stk.push(root->left);
            }
            if (root->right) {
                stk.push(root->right);
            }
        }
        reverse(vals.begin(), vals.end());
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        
        //postorderTraversal_Recursive(root, vals);
        postorderTraversal_Iterative(root, vals);
        
        return vals;
    }
};