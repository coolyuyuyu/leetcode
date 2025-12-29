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
    int longestConsecutive(TreeNode* root) {
        int ret = 0;
        std::function<void(TreeNode*, int, TreeNode*)> dfs = [&](TreeNode* cur, int lcs, TreeNode* pre) {
            if (!cur) { return; }

            if (pre && pre->val + 1 == cur->val) {
                ++lcs;
            }
            else {
                lcs = 1;
            }

            ret = std::max(ret, lcs);

            dfs(cur->left, lcs, cur);
            dfs(cur->right, lcs, cur);
        };
        dfs(root, 0, nullptr);

        return ret;
    }
};
