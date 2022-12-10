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
    int sumOfNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return sumOfNodes(root->left) + root->val + sumOfNodes(root->right);
    }

    int maxProduct_recursive(TreeNode* root, int sum, long long& ans) {
        if (!root) {
            return 0;
        }

        int lftSum = maxProduct_recursive(root->left, sum, ans);
        int rhtSum = maxProduct_recursive(root->right, sum, ans);

        ans = std::max({ans, (long long)(sum - lftSum) * lftSum, (long long)(sum - rhtSum) * rhtSum});

        return lftSum + root->val + rhtSum;
    }

    int maxProduct(TreeNode* root) {
        int sum = sumOfNodes(root);

        long long ans = INT_MIN;
        maxProduct_recursive(root, sum, ans);
        ans %= 1000000007;
        return ans;
    }
};
