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
    void inorderTraversalIter1(TreeNode* root, vector<int>& vals) {
        TreeNode* cur = root;
        stack<TreeNode*> stk;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                cur = stk.top();
                stk.pop();

                vals.push_back(cur->val);

                cur = cur->right;
            }
        }
    }

    void inorderTraversalIter2(TreeNode* root, vector<int>& vals) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur) {
            if (cur->left) {
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }

                if (pre->right) {
                    pre->right = NULL;
                    vals.push_back(cur->val);
                    cur = cur->right;
                }
                else {
                    pre->right = cur;
                    cur = cur->left;
                }
            }
            else {
                vals.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

    void inorderTraversalRecv(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        inorderTraversalRecv(root->left, vals);
        vals.push_back(root->val);
        inorderTraversalRecv(root->right, vals);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;

        inorderTraversalIter1(root, vals);
        //inorderTraversalIter2(root, vals);
        //inorderTraversalRecv(root, vals);

        return vals;
    }
};