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
    int maxDownwardSum(TreeNode* root, int& maxPathSum) {
        if (!root) {
            return 0;
        }

        int maxLftDownwardSum = max(maxDownwardSum(root->left, maxPathSum), 0);
        int maxRhtDownwardSum = max(maxDownwardSum(root->right, maxPathSum), 0);
        maxPathSum = std::max(maxPathSum, root->val + maxLftDownwardSum + maxRhtDownwardSum);
        return root->val + std::max(maxLftDownwardSum, maxRhtDownwardSum);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxDownwardSum(root, ans);
        return ans;
    }
};
