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
    int maxPathSum(TreeNode* root) {
        int maxPathSum = numeric_limits<int>::min();
        maxVerticalSum(root, maxPathSum);
        return maxPathSum;
    }

    int maxVerticalSum(TreeNode* root, int& maxPathSum) {
        if(root == nullptr) {
            return 0;
        }

        int lftMaxVerticalSum = max(maxVerticalSum(root->left, maxPathSum), 0);
        int rhtMaxVerticalSum = max(maxVerticalSum(root->right, maxPathSum), 0);
        maxPathSum = max(maxPathSum, root->val + lftMaxVerticalSum + rhtMaxVerticalSum);

        return root->val + max(lftMaxVerticalSum, rhtMaxVerticalSum);
    }
};