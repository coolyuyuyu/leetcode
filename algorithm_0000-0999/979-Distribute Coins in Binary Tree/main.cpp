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
    int distributeCoins(TreeNode* root) {
        int ret = 0;

        std::function<int(TreeNode*)> f = [&](TreeNode* root) {
            if (!root) { return 0; }

            int lftCoins = f(root->left);
            int rhtCoins = f(root->right);

            ret += abs(lftCoins) + abs(rhtCoins);

            return root->val + lftCoins + rhtCoins - 1;
        };
        f(root);

        return ret;
    }
};
