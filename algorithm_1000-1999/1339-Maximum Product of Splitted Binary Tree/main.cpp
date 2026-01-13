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
    int M = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        std::function<long long(TreeNode*)> dfs1 = [&](TreeNode* root) {
            if (!root) { return 0LL; }
            return (dfs1(root->left) + root->val + dfs1(root->right));
        };
        long long total = dfs1(root);

        long long ret = LLONG_MIN;
        std::function<long long(TreeNode*)> dfs2 = [&](TreeNode* root) {
            if (!root) { return 0LL; }
            long long sum = (dfs2(root->left) + root->val + dfs2(root->right));
            ret = std::max(ret, sum * (total - sum));
            return sum;
        };
        dfs2(root);

        return ret % M;
    }
};
