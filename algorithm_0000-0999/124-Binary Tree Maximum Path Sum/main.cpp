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
    int maxPathSum(TreeNode* root) {
        int maxTurnPathSum = INT_MIN;

        std::function<int(TreeNode*)> maxDownPathSum = [&](TreeNode* root) {
            if (!root) { return 0; }

            int lftDownPathSum = maxDownPathSum(root->left);
            int rhtDownPathSum = maxDownPathSum(root->right);
            maxTurnPathSum = std::max(maxTurnPathSum, root->val + std::max(lftDownPathSum, 0) + std::max(rhtDownPathSum, 0));

            return root->val + std::max({lftDownPathSum, rhtDownPathSum, 0});
        };
        maxDownPathSum(root);

        return maxTurnPathSum;
    }
};
