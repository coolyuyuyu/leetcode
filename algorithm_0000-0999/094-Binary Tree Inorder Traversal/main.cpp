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
    void inorderTraversal_Recursive(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        inorderTraversal_Recursive(root->left, vals);
        vals.push_back(root->val);
        inorderTraversal_Recursive(root->right, vals);
    }

    void inorderTraversal_Iterative(TreeNode* root, vector<int>& vals) {
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                while (root) {
                    stk.push(root);
                    root = root->left;
                }
            }
            else {
                root = stk.top();
                stk.pop();

                vals.push_back(root->val);
                root = root->right;
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;

        //inorderTraversal_Recursive(root, vals);
        inorderTraversal_Iterative(root, vals);

        return vals;
    }
};