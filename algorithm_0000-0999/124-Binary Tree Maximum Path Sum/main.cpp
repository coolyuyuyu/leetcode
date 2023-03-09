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
    int maxDownwardPathSum(TreeNode* root, int& maxPathSum) {
        if (!root) {
            return 0;
        }

        int maxLftDownwardPathSum = maxDownwardPathSum(root->left, maxPathSum);
        int maxRhtDownwardPathSum = maxDownwardPathSum(root->right, maxPathSum);
        int maxTurnPathSum = root->val + std::max(0, maxLftDownwardPathSum) + std::max(0, maxRhtDownwardPathSum);
        maxPathSum = std::max(maxPathSum, maxTurnPathSum);

        return root->val + std::max({0, maxLftDownwardPathSum, maxRhtDownwardPathSum});
    }

    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        maxDownwardPathSum(root, ret);
        return ret;
    }
};
