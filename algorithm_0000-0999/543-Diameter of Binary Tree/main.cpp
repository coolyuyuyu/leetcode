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
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        std::function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) { return 0; }

            int lftH = dfs(root->left);
            int rhtH = dfs(root->right);
            ret = std::max(ret, lftH+ rhtH);
            return std::max(lftH, rhtH) + 1;
        };

        dfs(root);

        return ret;
    }
};
