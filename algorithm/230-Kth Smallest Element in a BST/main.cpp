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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                root = stk.top();
                stk.pop();

                if (--k == 0) {
                    return root->val;
                }

                root = root->right;
            }
        }
        assert(false);
    }
};