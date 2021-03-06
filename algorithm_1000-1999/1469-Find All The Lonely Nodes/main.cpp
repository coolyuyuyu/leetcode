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
    void getLonelyNodes_Recursive(TreeNode* root, int siblingCnt, vector<int>& vals) {
        if (!root) {
            return;
        }
        if (siblingCnt == 1) {
            vals.push_back(root->val);
        }

        siblingCnt = (root->left ? 1 : 0) + (root->right ? 1 : 0);
        if (root->left) {
            getLonelyNodes_Recursive(root->left, siblingCnt, vals);
        }
        if (root->right) {
            getLonelyNodes_Recursive(root->right, siblingCnt, vals);
        }
    }

    void getLonelyNodes_Iterative(TreeNode* root, vector<int>& vals) {
        if (!root) {
            return;
        }

        stack<pair<TreeNode*, int>> stk; // node, siblingCnt;
        stk.emplace(root, 0);
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            int siblingCnt = stk.top().second;
            stk.pop();

            if (siblingCnt == 1) {
                vals.push_back(node->val);
            }

            siblingCnt = (node->left ? 1 : 0) + (node->right ? 1 : 0);
            if (node->right) {
                stk.emplace(node->right, siblingCnt);
            }
            if (node->left) {
                stk.emplace(node->left, siblingCnt);
            }
        }
    }

    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> vals;

        //getLonelyNodes_Recursive(root, 0, vals);
        getLonelyNodes_Iterative(root, vals);

        return vals;
    }
};