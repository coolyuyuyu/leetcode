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
    long long helper(TreeNode* root, long long& ret) {
        if (!root) { return 0LL; }

        long long sum = helper(root->left, ret) + helper(root->right, ret);
        if (sum == root->val) {
            ++ret;
        }

        return sum + root->val;
    }

    int equalToDescendants(TreeNode* root) {
        long long ret = 0;
        helper(root, ret);
        return ret;
    }
};
