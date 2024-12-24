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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ret = nullptr;
        std::function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) { return 0; }
            int cnt = dfs(root->left) + dfs(root->right);
            cnt += (root == p || root == q) ? 1 : 0;
            if (cnt == 2 && ret == nullptr) {
                ret = root;
            }
            return cnt;
        };
        dfs(root);

        return ret;
    }
};
