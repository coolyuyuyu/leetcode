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
    int minDiffInBST(TreeNode* root) {
        int minDiff = numeric_limits<int>::max();
        TreeNode* pre = NULL;
        stack<TreeNode*> nodes;
        TreeNode* cur = root;
        while (cur || !nodes.empty()) {
            if (cur) {
                nodes.push(cur);
                cur = cur->left;
            }
            else {
                cur = nodes.top();
                nodes.pop();

                if (pre) {
                    minDiff = min(minDiff, abs(cur->val - pre->val));
                }
                pre = cur;

                cur = cur->right;
            }
        }

        return minDiff;
    }
};